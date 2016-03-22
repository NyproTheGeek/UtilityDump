// 13/06/16
#ifndef SLOT_H
#define SLOT_H
#include <string>
using namespace std;

class Slot
{
private:
    string name;
    Attachment *attachments; /// TODO: Attachment class // position relative to bone // default pose for bone // name

public:
    Slot(int id, string name);
};
#endif // SLOT_H

