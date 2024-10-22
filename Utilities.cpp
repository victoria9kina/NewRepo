#include "Utilities.h"
#include <iostream>
#include <fstream>

int check_int(int max, int min) {
    int input;
    while (true) {
        std::cin >> input;
        if (std::cin.fail() || input < min || input > max) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, try again: ";
        }
        else {
            break;
        }
    }
    return input;
}

void EditPipe(std::vector<Pipe>& pipes) {
    int id;
    std::cout << "Enter pipe ID: ";
    std::cin >> id;
    for (auto& pipe : pipes) {
        if (pipe.id == id) {
            pipe.Edit();
            LogAction("Edited pipe with ID: " + std::to_string(id));
            return;
        }
    }
    std::cout << "Pipe with ID " << id << " not found." << std::endl;
}

void EditStation(std::vector<Station>& stations) {
    int id;
    std::cout << "Enter station ID: ";
    std::cin >> id;
    for (auto& station : stations) {
        if (station.id == id) {
            station.Edit();
            LogAction("Edited station with ID: " + std::to_string(id));
            return;
        }
    }
    std::cout << "Station with ID " << id << " not found." << std::endl;
}

void DeletePipe(std::vector<Pipe>& pipes) {
    int id;
    std::cout << "Enter pipe ID to delete: ";
    std::cin >> id;
    auto it = std::remove_if(pipes.begin(), pipes.end(), [id](const Pipe& pipe) { return pipe.id == id; });
    if (it != pipes.end()) {
        pipes.erase(it, pipes.end());
        LogAction("Deleted pipe with ID: " + std::to_string(id));
    }
    else {
        std::cout << "Pipe with ID " << id << " not found." << std::endl;
    }
}

void DeleteStation(std::vector<Station>& stations) {
    int id;
    std::cout << "Enter station ID to delete: ";
    std::cin >> id;
    auto it = std::remove_if(stations.begin(), stations.end(), [id](const Station& station) { return station.id == id; });
    if (it != stations.end()) {
        stations.erase(it, stations.end());
        LogAction("Deleted station with ID: " + std::to_string(id));
    }
    else {
        std::cout << "Station with ID " << id << " not found." << std::endl;
    }
}

void FindPipesByRepairStatus(const std::vector<Pipe>& pipes, bool isInRepair) {
    for (const auto& pipe : pipes) {
        if (pipe.isInRepair == isInRepair) {
            pipe.Display();
        }
    }
}

void FindStationsByUnusedWorkshops(const std::vector<Station>& stations, int minUnused) {
    for (const auto& station : stations) {
        if (station.workshops - station.workingWorkshops >= minUnused) {
            station.Display();
        }
    }
}

void LogAction(const std::string& action) {
    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << action << std::endl;
    }
}