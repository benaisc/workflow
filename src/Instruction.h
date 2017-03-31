#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__


virtual class Instruction
{
private:

public:
    Instruction();

    void print();

    //Ici on déclare les méthodes virtuelles
    //les méthodes qui permettront de manipuler
    //nos instructions indépendemment de leur types
    virtual void foo();
};

#endif
