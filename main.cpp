// © 2025 Jeremia Sell. All rights reserved.

#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <fstream>
#include <ctime>
#include <__msvc_filebuf.hpp>
#include <mmsystem.h>

#include "JBI.h"

#pragma comment(lib, "winmm.lib")

namespace fs = std::experimental::filesystem;




bool bool_sound = true;


string PATH_ASSETS = "data/data_assets.txt";
string PATH_LOGS = "data/logs.txt";
string line_assets;
string order;


time_t timestemp;


ifstream assets(PATH_ASSETS);

ofstream logs(PATH_LOGS);

vector<string> messages = {"start ", "Unknown Prompt: "};
vector<string> lines = {""};

void sound(string soundfile) {
    string Path__ = string("data/") + soundfile;
    if (bool_sound) {
        PlaySound(TEXT(Path__.c_str()), NULL, SND_FILENAME | SND_ASYNC);
    }
}

void log() {
    timestemp = time(0);
    tm *ltm = localtime(&timestemp);
    logs << "[" << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec <<"] " << "|| PROMPT: " << order << endl;
}

void startup() {
    system("color 7");
    PlaySound(TEXT("data/open.wav"), NULL, SND_FILENAME | SND_ASYNC);
    if (!assets.is_open()) {
        cout << "Could not open data_assets.txt" << endl;
    }

    if (!logs.is_open()) {
        cout << "Could not open logs.txt" << endl;
    }

    while (getline(assets, line_assets)) {
        lines.push_back(line_assets);
    }
}

void restart() {
    system("start CPPC.exe");

}

int main() {
    startup();
    while(true) {
        cout << "Enter prompt: ";
        getline(cin, order);
        if (order.substr(0, 0) == "") {
            log();
            //PlaySound(TEXT("data/enter.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
        if (order.substr(0, 6) == "start ") {
            string application = order.substr(6);
            cout << "Starting " << application << endl;

            system((messages[0] + application).c_str());
        }
        else if (order.substr(0, 4) == "sys ") {
            cout << "executing <|>" << endl;
            system(order.substr(4).c_str());
        }
        else if (order.substr(0, 4) == "say ") {
            cout << order.substr(4) << endl;
        }
        else if (order == "startup") {
            startup();
        }
        else if (order == "restart") {
            restart();
            break;
        }
        else if (order.substr(0, 4) == "rev ") {
            cout << reverb_s(order.substr(4)) << endl;
        }
        else if (order == "secret") {
            sound("secret.wav");
            cout << "Your order is ready" << endl;
        }
        else if (order.substr(0, 3) == "sus") {
            sound("sus.wav");
            cout << "Are you the imposter?" << endl;
        }
        else if (order == "rattle") {
            sound("rattle.wav");
            cout << "I had to much fun with designing this sounds" << endl;
        }
        else if (order == "sound") {
            if (bool_sound) {
                bool_sound = false;
                cout << bool_sound << endl;
            }
            else {
                bool_sound = true;
                cout << bool_sound << endl;
            }
        }
        else if (order == "news") {
            sound("Villager_News.wav");
            cout << "release date: unknown" << endl;
        }
        else if (order == "credits") {
            sound("credits.wav");
            cout << lines[3] << endl;
            _sleep(6000);
            cout << lines[4] << endl;
            _sleep(6000);
            cout << lines[5] << endl;
            _sleep(6000);
            cout << lines[6] << endl;
            _sleep(6000);
            cout << lines[7] << endl;
            _sleep(6000);
            cout << lines[8] << endl;
            assets.close();
        }
        else {
            cout << messages[1] << order << endl;
            sound("error.wav");
            //PlaySound(TEXT("data/error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
    }
}