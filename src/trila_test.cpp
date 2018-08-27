#include "renov_localization/Trilateration.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "localizer");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("range", 1000, );
    
    

    return 0;
}
