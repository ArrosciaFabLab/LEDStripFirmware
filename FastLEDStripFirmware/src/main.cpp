#include <Arduino.h> // Su un file .ino non è necessario
#include <FastLED.h>

/*
Schetch che utilizza la libreria FasLED

La strip è composta da LED WS2812B che hanno 3 pin in entrata e 3 pin in uscita (power, ground e data)

Ogni LED utilizzato utilizza circa 3 BYTES di RAM, quindi la striscia usa circa 3 x 150 = 450 BYTES di RAM
Ogni metro si striscia utilizza circa 2 Ah alla massima lumosità quindi l'intera striscia consuma 2 x 2,5 = 5 Ah
In totale Arduino UNO ha 2048 BYTES di RAM mentre Arduino MEGA 2560 ha 8192 BYTES
*/

 // PIN a cui è collegato il pin dati della strip
#define LED_PIN             6
// Tipo di LED utilizzato sulla strip (WS2812B)
#define LED_TYPE            WS2812
// Numero totale di LED sulla strip
#define NUM_LEDS            150
#define COLOR_ORDER         GRB
// Luminosità iniziale dei LED
#define BRIGHTNESS          64
// Tempo di aggiornamento dello stato dei LED ogni secondo
#define UPDATES_PER_SECOND  100

// Array dei LED che rappresenta la strip
CRGB leds[ NUM_LEDS ];

CRGBPalette16 currentPalette;

// La dichiarazione delle funzioni non è necessaria nel file .ino

/*
 *    Funzione che imposta la strip tutta accesa (150 LED) alla massima luminosità
 *    con tutti i LED di colore Blu Turchese.
 *    Il parametro booleano indica se accendere o spegnere la strip.
 *    L'animazione di accensione avviene dal centro verso l'esterno.
 *    L'animazione di spegnimento avviene dall'esterno verso il centro.
 */
void SetFullLenghtMode( bool bState );

/*
 *    Funzione che imposta la strip tutta spenda (150 LED) ad eccezzione di 3 LED in corrispondenza
 *    della coordinata X della punta della fresa che saranno accesi alla massima luminosità di colore
 *    Blu Turchese. I 5 LED a destra e sinistra di questi 3 LED dimuniranno progressivamente la loro
 *    luminosità del colore Blu Turchese fino allo spegnimento al 6° LED a destra e a sinistra.
 *    L'animazione di accensione avviene dal centro verso l'esterno.
 *    L'animazione di spegnimento avviene dall'esterno verso il centro.
 */
void SetFollowMode( bool bState, int nBitXPosition );

void setup()
{
    // Ritardo prima dell'accensione di 3 secondi
    delay( 3000 );

    // Inizializza la strip di LED
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

    // Imposta la luminosità iniziale dei LED
    FastLED.setBrightness( BRIGHTNESS );
}

void loop()
{
    FastLED.show();

    FastLED.delay( 1000 / UPDATES_PER_SECOND );

/*
    Vari metodi di impostare il colore Blu Turchese RAL 5018

    1)

    leds[0].red = 5;
    leds[0].green = 139;
    leds[0].blue = 140;

    o

    leds[0].r = 5;
    leds[0].g = 139;
    leds[0].b = 140;

    o

    leds[0][0] = 5;
    leds[0][1] = 139;
    leds[0][2] = 140;

    2)

    leds[0] = #058b8c;

    3)

    leds[0].setRGB( 5, 139, 140 );

    o

    leds[0].CRGB( 5, 139, 140 );
*/

    // Colore del LED
    leds[0].setRGB( 5, 139, 140 );

    // Luminosità del LED
    leds[0].setHue( 255 );
}
