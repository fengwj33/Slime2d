#ifndef TILEMAP_H
#define TILEMAP_H
#include "NLTmxMap.h"
#include "Define.h"
#include <iostream>
#include <stdlib.h>
#include<cstdio>
#include<string>
using namespace std;
class TileMap
{
    public:
        TileMap();
        virtual ~TileMap();
        NLTmxMap* tilemap=NULL;
        void loadMap(char * filename);
        int getLayerID(string layername);
        Vector2 getLayerSize(int layerID);
        Vector2 getLayerSize(string layername);
        int getLayerWidth(int layerID);
        int getLayerHeight(int layerID);
        int* getLayerData(int layerID);
        int* getLayerData(string layerID);
    protected:
    private:
        static void* loadFile( const char * filename, bool appendNull )
        {
            FILE* f = fopen( filename, "r" );
            if ( !f ) {
                return 0;
            }

            fseek( f, 0, SEEK_END );
            auto length = ftell( f ) + appendNull;
            fseek( f, 0, SEEK_SET );

            void* buffer = malloc( length );
            fread( buffer, length, 1, f );
            fclose( f );

            if ( appendNull ) {
                ((char*)buffer)[ length-1 ] = 0;
            }

            return buffer;
        }
};

#endif // TILEMAP_H
