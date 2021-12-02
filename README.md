# Corewar
## Desciption
Corewar is a game. A very special game. It consists of pitting little programs against one another in a virtual
machine.  

The goal of the game is to prevent the other programs from functioning correctly by using all available means.  

The game will, therefore, create a virtual machine in which the programs (written by the players) will face off. Each program’s objective is to “survive”, that is to say executing a special instruction ("live") that means I’mstillalive.  

These programs simultaneously execute in the virtual machine and in the same memory zone, which enables them to write on one another.  

The winner of the game is the last one to have executed the "live" instruction.

## The different part

The project is divided into three seperate parts:  

- **The Virtual Machine**
It houses the fighting binary programs (called champions), and provides them with a standard execution environment. It offers all kind of features that are useful to the champions’ fights. It must obviously be able to execute several programs at once...  

- **The Assembler**
It enables you to write programs designed to fight (the champions). It therefore understands the assembly language and generates binary programs that the virtual machine can execute.  

- **Champions**
This is your personal handiwork. They must be able to fight and to victoriously leave the virtual machine arena. They are written in the assembly language specific to our virtual machine (described further on).

## Authors

| [<img src="https://github.com/Cleopha.png?size=85" width=85><br><sub>Coline SEGURET</sub>](https://github.com/Cleopha) | [<img src="https://github.com/Breigner01.png?size=85" width=85><br><sub>Benjamin REIGNER</sub>](https://github.com/Breigner01) | [<img src="https://github.com/MrCubee.png?size=85" width=85><br><sub>Eliott BELINGUIER</sub>](https://github.com/MrCubee)
| :---: | :---: | :---: |
<h2 align=center>