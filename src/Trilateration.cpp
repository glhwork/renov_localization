#include "renov_localization/Trilateration.h"

Egien::Vector3d Trilateration::PosiCalcu(const PosDataVec3d &uwb_input) {

    Eigen::Vector3d location;

    if (uwb_input.size() < 3) {
        std::cout << "The quantity of stations is not enough" << std::endl;
    }

    // "rows" refers to the quantity of equations
    int n = uwb_input.size();
    rows = n*(n-1) / 2;
    Eigen::MatrixXd m(rows, 3);
    Eigen::VectorXd result(rows);

    for (size_t i = 0; i < n; i++) {
        double x1, x2, y1, y2, z1, z2;
        for (size_t j = i+1; j < n; j++) {
            x1 = uwb_input[i]._pos(0);
            y1 = uwb_input[i]._pos(1);
            z1 = uwb_input[i]._pos(2);

            x2 = uwb_input[j]._pos(0);
            y2 = uwb_input[j]._pos(1);
            z2 = uwb_input[j]._pos(2);

            
        }

    
    }
    


}