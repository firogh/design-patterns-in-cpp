#include <iostream>
class Player
{
public:
     virtual string get_name();
     virtual string send_instant_message(const string& mesg) const;
};


