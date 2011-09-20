#include "proxy-pattern.h"

bool InformWinner(const Player* player)
{
     string result;
     result = player->send_instant_message("You have won! Want to play again?");
     if(result == "yes") {
          cout << player->get_name()<< "wants to play again" <<endl;
          return true;
     }
     else{
          cout << player->get_name() << "does not want to play again" <<endl;
          return false;
     }
     
