#include <FastLED.h>

// Schetch che utilizza la libreria FasLED
// Ogni LED utilizzato utilizza circa 3 BYTES di RAM, quindi la striscia usa circa 3 x 150 = 450 BYTES di RAM
// Ogni metro si striscia utilizza circa 2 Ah alla massima lumosità quindi l'intera striscia consuma 2 x 2,5 = 5 Ah
// In totale Arduino UNO ha 2048 BYTES di RAM mentre Arduino MEGA 2560 ha 8192 BYTES

#define LED_PIN             5
#define LED_TYPE            WS2811
#define NUM_LEDS            150
#define COLOR_ORDER         GRB
#define BRIGHTNESS          64
#define UPDATES_PER_SECOND  100

CRGB leds[ NUM_LEDS ];

CRGBPalette16 currentPalette;

void setup()
{
    // Ritardo prima dell'accensione
    delay( 3000 );

    // Inizializza la strip di LED
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

    // Imposta la luminosità
    FastLED.setBrightness(  BRIGHTNESS );
}

void loop()
{
    FastLED.show();

    FastLED.delay( 1000 / UPDATES_PER_SECOND );
}
