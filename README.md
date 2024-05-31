# RL_turnbasedcombat
RL Agent for a turn-based combat, using Learning Agents plugin in Unreal Engine 5
This repository does not include the game that was used to test this agent.
It is more an example on how to adapt the Learning Agents plugin to custom needs, in
this case a turn-based combat.

This project consists of:

RL_Enemy: This folder contains the Files with the used blueprints for the RL agent.
The Learning Agents Plugin was used to set up the agent. There are a lot of 
missing references since it was implemented in a custom game which is not included
in this repository. 

RL_Logger: This inlcudes the blueprint for the logger class, it takes the parameters and
the source handles the CSV handling.

LoggerSource: Source code for the Logger class.
BP_LoggertoCSV.cpp, BP_LoggertoCSV.h
