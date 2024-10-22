#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include "Pipe.h"
#include "Station.h"

int check_int(int max, int min);
void EditPipe(std::vector<Pipe>& pipes);
void EditStation(std::vector<Station>& stations);
void DeletePipe(std::vector<Pipe>& pipes);
void DeleteStation(std::vector<Station>& stations);
void FindPipesByRepairStatus(const std::vector<Pipe>& pipes, bool isInRepair);
void FindStationsByUnusedWorkshops(const std::vector<Station>& stations, int minUnused);
void LogAction(const std::string& action);

#endif
#pragma once
