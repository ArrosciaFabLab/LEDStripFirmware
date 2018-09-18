#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

// Schetch che utilizza la libreria Adafruit NeoPixel
// Ogni LED utilizzato utilizza circa 3 BYTES di RAM, quindi la striscia usa circa 3 x 150 = 450 BYTES di RAM
// Ogni metro si striscia utilizza circa 2 Ah alla massima lumosità quindi l'intera striscia consuma 2 x 2,5 = 5 Ah
// In totale Arduino UNO ha 2048 BYTES di RAM mentre Arduino MEGA 2560 ha 8192 BYTES

#define LED_STRIP_DATA_PIN  6
#define LED_NUMBER          150
#define LED_BRIGHTNESS      64
// NEO_KHZ800 800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
// NEO_KHZ400 400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
// NEO_GRB Pixels are wired for GRB bitstream (most NeoPixel products)
// NEO_RGB Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

// Creo l'oggetto LEDStrip
// Parametro 1 = Numero di LED di cui è composta la striscia (1 metro di una striscia di media densità è composta da 60 LED)
// Parametro 2 = PIN di Arduino a cui è collegata la linea dati della striscia
// Parametro 3 = Tipo di LED presenti sulla striscia
Adafruit_NeoPixel objLEDStrip = Adafruit_NeoPixel( LED_NUMBER, LED_STRIP_DATA_PIN, NEO_GRB + NEO_KHZ800 );

void setup()
{
    objLEDStrip.begin();

    // Imposta la luminosità dei LED al 25% (100% = 256)
    objLEDStrip.setBrightness( LED_BRIGHTNESS );

    // Inizializza la striscia spegnendo tutti i LED
    objLEDStrip.show();
}

void loop()
{

}
