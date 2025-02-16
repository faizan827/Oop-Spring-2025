#include <iostream>
#include <string>
using namespace std;

class MusicPlayer {
    private:
        string playlist[500];
        string currentplayingsong;
        int count;

    public:
        MusicPlayer() {
            playlist[0] = "khel jamay ga";
            playlist[1] = "hello";
            playlist[2] = "love";
            playlist[3] = "hi";
            playlist[4] = "Teenage Dream";
            currentplayingsong = "me";
            count = 5;
        }

        void addSongs(int numSongs) {
            if (numSongs > 0) {
                for (int i = count; i < (count + numSongs); i++) {
                    cout << "Enter song " << i + 1 << " to add to the playlist: ";
                    getline(cin, playlist[i]);
                }
                count += numSongs;
                cout << "Songs added successfully!" << endl;
            } else {
                cout << "Invalid number of songs." << endl;
            }
        }

        void deleteSongs(int numSongs) {
            if (numSongs > 0) {
                for (int i = 0; i < numSongs; i++) {
                    string songName;
                    cout << "Enter the name of song " << i + 1 << " to remove: ";
                    getline(cin, songName);
                    bool found = false;
                    for (int j = 0; j < count; j++) {
                        if (songName == playlist[j]) {
                            for (int k = j; k < count - 1; k++) {
                                playlist[k] = playlist[k + 1];
                            }
                            count--;
                            found = true;
                            cout << "Song removed successfully!" << endl;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Song not found in the playlist." << endl;
                    }
                }
            } else {
                cout << "Invalid number of songs." << endl;
            }
        }

        void playSong(string songName) {
            bool songFound = false;
            for (int i = 0; i < count; i++) {
                if (songName == playlist[i]) {
                    currentplayingsong = songName;
                    cout << "Now playing: " << songName << endl;
                    songFound = true;
                    break;
                }
            }
            if (!songFound) {
                cout << "Song not found in the playlist." << endl;
            }
        }

        void showPlaylist() {
            cout << "\n-----------------\n";
            if (count == 0) {
                cout << "The playlist is empty!" << endl;
            } else {
                cout << "Playlist Songs:" << endl;
                for (int i = 0; i < count; i++) {
                    cout << i + 1 << ". " << playlist[i] << endl;
                }
            }
            cout << "-----------------\n\n";
        }
};

int main() {
    int choice, num;
    string songName;
    MusicPlayer alizafar; 

    while (true) {
        cout << "1. Add songs to the playlist." << endl;
        cout << "2. Remove songs from the playlist." << endl;
        cout << "3. Display the playlist." << endl;
        cout << "4. Play a song from the playlist." << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number of songs to add: ";
                cin >> num;
                alizafar.addSongs(num);
                break;
            case 2:
                cout << "Enter the number of songs to remove: ";
                cin >> num;
                alizafar.deleteSongs(num);
                break;
            case 3:
                alizafar.showPlaylist();
                break;
            case 4:
                cin.ignore();
                cout << "Enter the name of the song to play: ";
                getline(cin, songName);
                alizafar.playSong(songName);
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }
    return 0;
}
