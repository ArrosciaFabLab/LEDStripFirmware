#include "FastLEDStrip.hpp"   // Libreria di gestione della striscia LED
#include <Arduino.h>        // Su un file .ino non è necessario

/*
Schetch di test sulla striscia LED che utilizza la libreria FasLED
*/

// La dichiarazione delle funzioni non è necessaria nel file .ino

void DebugSetup();

// Setup inizale di Arduino
void setup()
{
    // Inizializzo il logging sul monitor seriale
    DebugSetup();

    Serial.println( "--- Sto inizializzando la scheda Arduino" );

	// Configurazione iniziale della LED strip
    LEDStripSetup();

    Serial.println( "--- Ho finito di inizializzare la scheda Arduino" );
}

// Loop standard di Arduino
void loop()
{
    Serial.println( "--- Inizio il loop principale della scheda Arduino" );

    FastLED.show();

    FastLED.delay( 1000 / UPDATES_PER_SECOND );

    Serial.println( "Accendo tutta la strip di LED" );

    // Accendo tutta la strip alla massima luminosità di colore Turchese
    StripFullLenghtMode( ON );

    Serial.println( "Spengo tutta la strip di LED" );

    // Spengo tutta la strip
    StripFullLenghtMode( OFF );

    /*for ( size_t i = 0; i < 29 ; i++ )
    {
        StripFollowMode( ON, 75 + i );
        StripFollowMode( OFF, 75 + i );
    }
    for ( size_t i = 29; i > 0 ; i-- )
    {
        StripFollowMode( ON, 75 + i );
        StripFollowMode( OFF, 75 + i );
    }*/

    //CylonBounce( 255, 0, 0, 4, 10, 50 ); // Red
    //CylonBounce( 64,224, 208, 4, 10, 50 ); // Turquoise
    //CylonBounce( 32, 178, 170, 4, 10, 50 ); // LightSeaGreen
    //CylonBounce( 72, 209, 204, 4, 10, 50 ); // MediumTurquoise

    Serial.println( "Test del Cyclon Eye" );

    CylonBounce( 0, 206, 209, 4, 10, 50 ); // DarkTurquoise
}

void DebugSetup()
{
    Serial.begin( 9600 );
    Serial.println( "Ho inizializzato il debug su monitor seriale");
}
