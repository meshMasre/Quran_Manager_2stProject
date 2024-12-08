#include <iostream>
#include <string>
#include <fstream>
#include "Ds.cpp"
#include "Playlist.cpp"
using namespace std;
#pragma once

class Container
{
private:
    DLL<playList> Playlists; // List of playlists

public:
    Container() {};

    ~Container() {};
    void AddPlayList(const playList &NewPlayList)
    {
        Playlists.InsertBegin(NewPlayList);
    }
    void GetNumOfPlaylists()
    {
        cout << "The number of playlists is : " << Playlists.GetCapacity() << endl;
    }
};
