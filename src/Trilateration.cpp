#include "renov_localization/Trilateration.h"

using Trila::Trilateration;
Eigen::Vector3d Trilateration::PosiCalcu(const PosDataVec3d &uwb_input) {

    Eigen::Vector3d location;
    int n, rows;

    if (uwb_input.size() < 3) {
        std::cout << "The quantity of stations is not enough" << std::endl;
    }

    // "rows" refers to the quantity of equations
    n = uwb_input.size();
    rows = n*(n-1) / 2;
    Eigen::MatrixXd m(rows, 3);
    Eigen::VectorXd result(rows);

    for (size_t i = 0; i < n; i++) {

        double x1, x2, y1, y2, z1, z2;
        double d1, d2;
        x1 = uwb_input[i]._pos(0);
        y1 = uwb_input[i]._pos(1);
        z1 = uwb_input[i]._pos(2);
        d1 = uwb_input[i]._dis;

        for (size_t j = i+1; j < n; j++) {

            x2 = uwb_input[j]._pos(0);
            y2 = uwb_input[j]._pos(1);
            z2 = uwb_input[j]._pos(2);
            d2 = uwb_input[j]._dis;

            m << x1 - x2,
                 y1 - y2,
                 z1 - z2;
            result << (pow(x1, 2) - pow(x2, 2) +
                       pow(y1, 2) - pow(y2, 2) +
                       pow(z1, 2) - pow(z2, 2) +
                       pow(d2, 2) - pow(d1, 2)) / 2;
        }    
    }
    location = m.jacobiSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(result);
    return location;
}