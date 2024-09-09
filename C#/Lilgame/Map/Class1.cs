//This is a draft of the data structure I intend on using in the adventure game I intend on making
namespace Map;
using System;
public struct Landtile
{
    public int x_cord;
    public int y_cord;
    public Landtype land_type;
    public Landtile(int x_in,int y_in){
        x_cord = x_in;
        y_cord = y_in;

        Random random = new Random();
        int rand = random.Next(0, 11);

        land_type = new Landtype(rand);
    }

}

public struct Landtype{
   string type_name;
   int visability;
   int danger;
   bool is_road;
   bool is_town;
   int is_connected;
   bool passability;
   bool need_boat;

   public Landtype(int rand){
    switch(rand){
        case 0:
        type_name = "Plains";
        visability = 2;
        danger = 1;
        is_road = false;
        is_town = false;
        is_connected = -1;
        passability = true;
        need_boat = false;

        break;

        case 1:
        type_name = "Hills";
        visability = 1;
        danger = 2;
        is_road = false;
        is_town = false;
        is_connected = -1;
        passability = true;
        need_boat = false;
        break; 

        case 2:
        type_name = "River";
        visability = 2;
        danger = 2;
        is_road = false;
        is_town = false;
        is_connected = 0;
        passability = true;
        need_boat = true;
        break;

        default:
        type_name = "Road";
        visability = 2;
        danger = 2;
        is_road = true;
        is_town = false;
        is_connected = 0;
        passability = true;
        need_boat = false;
        break;
    }
   }
}