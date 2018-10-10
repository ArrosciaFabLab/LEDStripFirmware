#include <Arduino.h> // Su un file .ino non è necessario
#include <FastLED.h>

/*
Schetch che utilizza la libreria FasLED

La strip è composta da LED WS2812B che hanno 3 pin in entrata e 3 pin in uscita (power, ground e data)

Ogni LED utilizzato utilizza circa 3 BYTES di RAM, quindi la striscia usa circa 3 x 150 = 450 BYTES di RAM
Ogni metro si striscia utilizza circa 2 Ah alla massima lumosità quindi l'intera striscia consuma 2 x 2,5 = 5 Ah
In totale Arduino UNO ha 2048 BYTES di RAM mentre Arduino MEGA 2560 ha 8192 BYTES
*/

/*
    Vari metodi di impostare il colore Blu Turchese RAL 5018

    1)

    objLEDStrip[0].red = 5;
    objLEDStrip[0].green = 139;
    objLEDStrip[0].blue = 140;

    o

    objLEDStrip[0].r = 5;
    objLEDStrip[0].g = 139;
    objLEDStrip[0].b = 140;

    o

    objLEDStrip[0][0] = 5;
    objLEDStrip[0][1] = 139;
    objLEDStrip[0][2] = 140;

    2)

    objLEDStrip[0] = #058b8c;

    3)

    objLEDStrip[0].setRGB( 5, 139, 140 );

    o

    objLEDStrip[0].CRGB( 5, 139, 140 );
	
	o
	
	objLEDStrip[0] = CRGB::Turchese
*/

// PIN a cui è collegato il pin dati della strip
#define LED_PIN             6
// Tipo di LED utilizzato sulla strip (WS2812B)
#define LED_TYPE            WS2812
// Numero totale di LED sulla strip
#define NUM_LEDS            150
//
#define COLOR_ORDER         GRB
// Luminosità iniziale dei LED (da 0 a 255)
#define BRIGHTNESS          64
// Tempo di aggiornamento dello stato dei LED ogni secondo
#define UPDATES_PER_SECOND  100
// Velocità di accensione o spegnimento del successivo LED
#define WAIT_TO_NEXT		20
// Stato del LED a spento
#define OFF					false
// Stato del LED a accesso
#define ON					true

// Array dei LED che rappresenta la strip
CRGB objLEDStrip[ NUM_LEDS ];

CRGBPalette16 currentPalette;

// La dichiarazione delle funzioni non è necessaria nel file .ino

/*
 *    Funzione che imposta la strip tutta accesa (150 LED) alla massima luminosità
 *    con tutti i LED di colore Turchese.
 *    Il parametro booleano indica se accendere o spegnere la strip.
 *    L'animazione di accensione avviene dal centro verso l'esterno.
 *    L'animazione di spegnimento avviene dall'esterno verso il centro.
 */
void SetFullLenghtMode( bool bState );

/*
 *    Funzione che imposta la strip tutta spenda (150 LED) ad eccezzione di 3 LED in corrispondenza
 *    della coordinata X della punta della fresa che saranno accesi alla massima luminosità di colore
 *    Turchese. I 5 LED a destra e sinistra di questi 3 LED dimuniranno progressivamente la loro
 *    luminosità del colore Turchese fino allo spegnimento al 6° LED a destra e a sinistra.
 *    L'animazione di accensione avviene dal centro verso l'esterno.
 *    L'animazione di spegnimento avviene dall'esterno verso il centro.
 */
void SetFollowMode( bool bState, int nBitXPosition );

// Setup inizale di Arduino
void setup()
{
    // Ritardo prima dell'accensione di 3 secondi
    delay( 3000 );

    // Inizializza la strip di LED
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>( objLEDStrip, NUM_LEDS ).setCorrection( TypicalLEDStrip );

    // Imposta la luminosità iniziale dei LED
    FastLED.setBrightness( BRIGHTNESS );
}

// Loop standard di Arduino
void loop()
{
    FastLED.show();

    FastLED.delay( 1000 / UPDATES_PER_SECOND );

    // Accendo tutta la strip alla massima luminosità di colore Turchese
    SetFullLenghtMode( ON );

    // Spengo tutta la strip
    SetFullLenghtMode( OFF );
}

/*
 *    Funzione che imposta la strip tutta accesa o spenta alla massima luminosità
 *    con tutti i LED di colore Blu Turchese (se accesa).
 *    Il parametro booleano indica se accendere o spegnere la strip.
 *    L'animazione di accensione avviene dal centro verso l'esterno.
 *    L'animazione di spegnimento avviene dall'esterno verso il centro.
 */
void SetFullLenghtMode( bool bState )
{

    // Si vuole spegnere totalmente la strip
    if ( bState == OFF )
    {
        for ( size_t i = 0; i < ( ( NUM_LEDS / 2 ) - 1 ); i++ )
        {
            // Parto dal primo LED a sinistra e spengo tutti i LED da
            // sinistra a destra fino al metà del numero dei LED della strip
            objLEDStrip[i] = CRGB::Black;
			FastLED.show();

            // Parto dal primo LED a destra e spengo tutti i LED da
            // destra a sinistra fino al metà del numero dei LED della strip
            objLEDStrip[NUM_LEDS - 1 - i] = CRGB::Black;
			FastLED.show();
			
			delay( WAIT_TO_NEXT );
        }
    }
	
	// Si vuole accendere totalmente la strip con una animazione che parte dal primo LED
    // al centro e proseguendo da entrambi i lati verso l'esterno
    else
    {
        for ( size_t i = 1; i < ( ( NUM_LEDS / 2 ) + 1 ); i++ )
        {
            // Parto dal primo LED al centro e accendo tutti i LED da
            // destra a sinistra fino al primo LED a sinistra della strip
            objLEDStrip[( NUM_LEDS / 2 ) - i] = CRGB::Turquoise;
			FastLED.show();

            // Parto dal primo LED a destra di quello al centro e accendo
            // tutti i LED a destra fino all'ultimo LED a destra della strip
            objLEDStrip[i + ( ( NUM_LEDS / 2 ) - 1)] = CRGB::Turquoise;
			FastLED.show();
			
			delay( WAIT_TO_NEXT );
        }
    }
}

/*
 *    Funzione che imposta la strip tutta spenda (150 LED) ad eccezzione di 3 LED in corrispondenza
 *    della coordinata X della punta della fresa che saranno accesi alla massima luminosità di colore
 *    Turchese. I 5 LED a destra e sinistra di questi 3 LED dimuniranno progressivamente la loro
 *    luminosità del colore Turchese fino allo spegnimento al 6° LED a destra e a sinistra.
 *    L'animazione di accensione avviene dal centro verso l'esterno.
 *    L'animazione di spegnimento avviene dall'esterno verso il centro.
 */
void SetFollowMode( bool bState, int nBitXPosition )
{
    // Si vuole spegnere il cursore della strip
    if ( bState == OFF )
    {
		// a
    }
    else // Si vuole accendere il cursore della strip
    {
		// b
    }
}
