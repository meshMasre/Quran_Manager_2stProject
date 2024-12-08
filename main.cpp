#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <mmsystem.h>
#include <tchar.h>
#include "Ds.cpp"
#include "Audio.cpp"
#include "Playlist.cpp"
#include "Container.cpp"
using namespace std;
#pragma comment(lib, "winmm.lib")

int ReadNumberInRange(int From, int To, string Message)
{
    int Number;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number < From || Number > To);
    return Number;
}

string ReadString(string message)
{
    string Order;
    cout << message;
    cin >> Order;
    return Order;
}

void PrintList(int &Number)
{
    cout << "===============================================================\n";
    cout << "\t\tQuraan playlist manager menu\n";
    cout << "1. Add a new playlist\n";
    cout << "2. Add Shurah to an existing playlist\n";
    cout << "3. Remove Shurah from an existing playlist\n";
    cout << "4. Update the order of existing playlist\n";
    cout << "5. Display all current playlists\n";
    cout << "6. Display all playlists shurah\n";
    cout << "7. Display shurah in a specific playlist\n";
    cout << "8. Play shurah from specific playlist\n";
    cout << "   Use left arrow (<-) to play the previous shurah\n";
    cout << "   Use right arrow (->) to play the next shurah\n";
    cout << "   Use up arrow to pause the current shurah\n";
    cout << "   Use down arrow to resume the current shurah\n";
    cout << "   Press q to exit current playlist & return back to menu\n";
    cout << "9. Save an existing playlist to a file\n";
    cout << "10. Load an existing playlist from a file\n";
    cout << "11. Remove an existing playlist\n";
    cout << "12. Exit\n";
    cout << "===============================================================\n";
    Number = ReadNumberInRange(1, 12, "Your choice: ");
}

int main()
{
    Container c1;
    int Choice;
    do
    {
        Audio a1;
        PrintList(Choice);
        switch (Choice)
        {
        case 2:
            a1.SetData(ReadString("Enter path: "), ReadString("Enter type: "), ReadString("Enter Surah name: "));
            break;
        case 1:
            c1.AddPlayList(ReadString("Enter name of Reader: "));
            break;
        case 5:
            c1.GetNumOfPlaylists();
            break;
        case 8:
            a1.PlaySurah();
        default:
            break;
        }
        /*if (Choice == 2)
        {
            a1.SetData(ReadString("Enter path: "), ReadString("Enter type: "), ReadString("Enter Surah name: "));
        }
        if (Choice == 8)
        {
            a1.PlaySurah();
        }*/
    } while (Choice != 12);

    system("pause");
    return 0;
}
