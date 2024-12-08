#include <iostream>
#include <string>
#include "Ds.cpp"
#include "Audio.cpp"
using namespace std;
#pragma once

class playList // Maked By Dll
{
private:
    DLL<Audio> Surahs; // A list of surahs
    string name;       // The name of the playlist(Reader)
    int NumOfSurahs = 0;

public:
    // Constructor
    playList(const string &PlaylistName = "Abdelbaset_Abdelsamad") : name(PlaylistName) {};
    // Destructor
    ~playList() {};
    // Add Surah
    void AddSurah(const Audio &surah)
    {
        Surahs.InsertEnd(surah);
        NumOfSurahs++;
    }
    // Display Surah
    void DisplaySurah() {};
};