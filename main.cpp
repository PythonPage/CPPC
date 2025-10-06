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

enum class mode {
    begins,
    is
};

string PATH_ASSETS = "data/data_assets.txt";
string PATH_LOGS = "data/logs.txt";
string line_assets;
string order;


time_t timestemp;


ifstream assets(PATH_ASSETS);

ofstream logs(PATH_LOGS);

vector<string> messages = {"start ", "Unknown Prompt: "};
vector<string> lines = {""};

class program {
private:
    string name;
    string ver;
    string author;
public:
    program(string n, string v, string a) {
        name = n;
        ver = v;
        author = a;
    }
    string extrude(string info) {
        if (info == "name") {
            return name;
        }
        if (info == "version") {
            return ver;
        }
        if (info == "author") {
            return author;
        }
    }
    void set(string var) {
        if (var == "name") {
            name = var;
        }
        if (var == "version") {
            ver = var;
        }
        if (var == "author") {
            author = var;
        }
    }
    void restart() {
        system(("start " + name + ".exe").c_str());
        exit(0);
    }
    string getName() {
        return name;
    }
    string getVersion() {
        return ver;
    }
    string getAuthor() {
        return author;
    }
};

class user {
private:
    string name;
    string age;
    string ID;
    int _id;
public:
    user(string n, int a) {
        name = n;
        age = a;
        ID = name + "." + age;
    }
    string Id() {
        return ID;
    }
    string Name() {
        return name;
    }
    string Age() {
        return age;
    }
    void setName(string new_name) {
        name = new_name;
        ID = name + "." + age;
    }
    void setAge(string new_age) {
        age = new_age;
        ID = name + "." + age;
    }
};

class dev {
public:
    dev() {
    }
    void install(string p) {
        system(("choco install " + p + " -y").c_str());
    }
    void emergency() {
        system("shutdown /s<");
    }


};

class lg {
public:
    lg() {

    }
    void addLog() {
        timestemp = time(0);
        tm *ltm = localtime(&timestemp);
        logs << "[" << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec <<"] " << "|| PROMPT: " << order << endl;
    }
    //void clear() {
    //    logs.clear();
    //}
};

program p(
    "CPPC",
    "0.0.2",
    "Jeremia Sell"
    );
user u("Jeremia", 18);

dev d;

lg lo;

void sound(string soundfile) {
    string Path__ = string("data/") + soundfile;
    if (bool_sound) {
        PlaySound(TEXT(Path__.c_str()), NULL, SND_FILENAME | SND_ASYNC);
    }
}

void startup() {
    system("color 7");
    //PlaySound(TEXT("data/open.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
    exit(0);
}

int main() {
    startup();
    while(true) {
        cout << "Enter prompt: ";
        getline(cin, order);
        lo.addLog();
        //PlaySound(TEXT("data/enter.wav"), NULL, SND_FILENAME | SND_ASYNC);
        if      (order.substr(0, 8) == "install ") {
            string p = order.substr(0, 8);
            d.install(p);
        }
        else if (order.substr(0, 4) == "rev ") {
            cout << reverb_s(order.substr(4)) << endl;
        }
        else if (order.substr(0, 4) == "say ") {
            cout << order.substr(4) << endl;
        }
        else if (order.substr(0, 6) == "start ") {
            string application = order.substr(6);
            cout << "Starting " << application << endl;

            system((messages[0] + application).c_str());
        }
        else if (order.substr(0, 3) == "sus") {
            sound("sus.wav");
            cout << "Are you the imposter?" << endl;
        }
        else if (order.substr(0, 4) == "sys ") {
            cout << "executing <|>" << endl;
            system(order.substr(4).c_str());
        }
        else if (order.substr(0, 9) == "user age ") {
            u.setAge(order.substr(9));
        }
        else if (order.substr(0, 10) == "user  name ") {
            u.setName(order.substr( 10));
        }
        else if (order == "-v") {
            cout << "Version: " << p.extrude("version") << endl;
        }
        else if (order == "-r") {
            restart();
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
        else if (order == "dev logs clear") {

        }
        else if (order == "emergency") {
            d.emergency();
        }
        else if (order == "news") {
            sound("Villager_News.wav");
            cout << "release date: unknown" << endl;
        }
        else if (order == "rattle") {
            sound("rattle.wav");
            cout << "I had to much fun with designing this sounds" << endl;
        }
        else if (order == "restart") {
            restart();
            break;
        }
        else if (order == "secret") {
            sound("secret.wav");
            cout << "Your order is ready" << endl;
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
        else if (order == "startup") {
            startup();
        }
        else if (order == "user info") {
            cout << "Name: " << u.Name() << endl;
            cout << "Age: " << u.Age() << endl;
            cout << "Id: " << u.Id() << endl;
        }
        else {
            cout << messages[1] << order << endl;
            //sound("error.wav");
            //PlaySound(TEXT("data/error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
    }
}