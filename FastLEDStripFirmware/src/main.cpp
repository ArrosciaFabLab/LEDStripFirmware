#include <FastLED.h>

/*
Schetch che utilizza la libreria FasLED

La strip è composta da LED WS2812B che hanno 3 pin in entrata e 3 pin in uscita (power, ground e data)

Ogni LED utilizzato utilizza circa 3 BYTES di RAM, quindi la striscia usa circa 3 x 150 = 450 BYTES di RAM
Ogni metro si striscia utilizza circa 2 Ah alla massima lumosità quindi l'intera striscia consuma 2 x 2,5 = 5 Ah
In totale Arduino UNO ha 2048 BYTES di RAM mentre Arduino MEGA 2560 ha 8192 BYTES
*/

#define LED_PIN             6
#define LED_TYPE            WS2811
#define NUM_LEDS            150
#define COLOR_ORDER         GRB
#define BRIGHTNESS          64
#define UPDATES_PER_SECOND  100

// Array dei LED
CRGB leds[ NUM_LEDS ];

CRGBPalette16 currentPalette;

void setup()
{
    // Ritardo prima dell'accensione di 3 secondi
    delay( 3000 );

    // Inizializza la strip di LED
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

    // Imposta la luminosità
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
