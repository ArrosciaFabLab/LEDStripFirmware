#include <Arduino.h> // Su un file .ino non è necessario
#include <Adafruit_NeoPixel.h>

// Schetch che utilizza la libreria Adafruit NeoPixel
// Ogni LED utilizzato utilizza circa 3 BYTES di RAM, quindi la striscia usa circa 3 x 150 = 450 BYTES di RAM
// Ogni metro si striscia utilizza circa 2 Ah alla massima lumosità quindi l'intera striscia consuma 2 x 2,5 = 5 Ah
// In totale Arduino UNO ha 2048 BYTES di RAM mentre Arduino MEGA 2560 ha 8192 BYTES

#define LED_STRIP_DATA_PIN  6
// Numero totale di LED sulla strip
#define LED_NUMBER          150
// Luminosità iniziale dei LED (da 0 a 255)
#define LED_BRIGHTNESS      255
// NEO_KHZ800 800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
// NEO_KHZ400 400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
// NEO_GRB Pixels are wired for GRB bitstream (most NeoPixel products)
// NEO_RGB Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

// Creo l'oggetto LEDStrip
// Parametro 1 = Numero di LED di cui è composta la striscia (1 metro di una striscia di media densità è composta da 60 LED)
// Parametro 2 = PIN di Arduino a cui è collegata la linea dati della striscia
// Parametro 3 = Tipo di LED presenti sulla striscia
Adafruit_NeoPixel objLEDStrip = Adafruit_NeoPixel( LED_NUMBER, LED_STRIP_DATA_PIN, NEO_GRB + NEO_KHZ800 );

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

// Setup inizale di Arduino
void setup()
{
    objLEDStrip.begin();

    // Imposta la luminosità dei LED al 25% (100% = 256)
    objLEDStrip.setBrightness( LED_BRIGHTNESS );

    // Inizializza la striscia spegnendo tutti i LED
    objLEDStrip.show();
}

// Loop standard di Arduino
void loop()
{

}

void SetFullLenghtMode( bool bState )
{

    // Si vuole spegnere totalmente la strip
    if ( bState == false )
    {

    }
    else // Si vuole accendere totalmente la strip
    {

    }
}

void SetFollowMode( bool bState, int nBitXPosition )
{
    // Si vuole spegnere il cursore della strip
    if ( bState == false )
    {

    }
    else // Si vuole accendere il cursore della strip
    {

    }
}
