#include <iostream>
#include <vector>
#include "Pipe.h"
#include "Station.h"
#include "Utilities.h"

int menu() {
    int k = -1;
    while (true) {
        std::cout << "   Menu" << std::endl
            << "1) Add pipe" << std::endl
            << "2) Add CS" << std::endl
            << "3) View objects" << std::endl
            << "4) Edit pipe" << std::endl
            << "5) Edit CS" << std::endl
            << "6) Save data" << std::endl
            << "7) Load data" << std::endl
            << "8) Delete pipe" << std::endl
            << "9) Delete station" << std::endl
            << "10) Find pipes by repair status" << std::endl
            << "11) Find stations by unused workshops" << std::endl
            << "0) Exit" << std::endl
            << "Enter the command you would like to execute (0 to 11): ";
        k = check_int(11, 0);
        return k;
    }
}

int main() {
    std::vector<Pipe> pipes;
    std::vector<Station> stations;

    while (true) {
        int choice = menu();
        switch (choice) {
        case 1:
            pipes.push_back(Pipe::CreatePipe());
            LogAction("Added new pipe");
            break;
        case 2:
            stations.push_back(Station::CreateStation());
            LogAction("Added new station");
            break;
        case 3:
            for (const auto& pipe : pipes)
                pipe.Display();
            for (const auto& station : stations)
                station.Display();
            break;
        case 4:
            EditPipe(pipes);
            break;
        case 5:
            EditStation(stations);
            break;
        case 6:
            // Save logic here
            LogAction("Saved data");
            break;
        case 7:
            // Load logic here
            LogAction("Loaded data");
            break;
        case 8:
            DeletePipe(pipes);
            break;
        case 9:
            DeleteStation(stations);
            break;
        case 10:
            FindPipesByRepairStatus(pipes, true);
            break;
        case 11:
            FindStationsByUnusedWorkshops(stations, 1);
            break;
        case 0:
            return 0;
        }
    }
}


