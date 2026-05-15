#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    double P_v, P, rho;
    cout << "Calculation of critical cavitation velocity\n";
    cout << "Enter saturated vapor pressure P_v (kPa): ";
    cin >> P_v;
    cout << "Enter static pressure in the flow P (kPa): ";
    cin >> P;
    cout << "Enter fluid density rho (kg/m^3): ";
    cin >> rho;
    double P_v_Pa = P_v * 1000.0;
    double P_Pa = P * 1000.0;
    double diff = P_v_Pa - P_Pa;
    cout << "\nResult using the formula from the file\n";
    if (diff <= 0.0) {
        cout << "Radicand <= 0, cavitation does not occur\n";
    } else {
        double V_kp = sqrt(diff / rho);
        cout << "Critical velocity: " << V_kp << " m/s\n";
    }
    double diff_corr = P_Pa - P_v_Pa;
    cout << "\nResult\n";
    if (diff_corr <= 0.0) {
        cout << "Cavitation is inevitable\n";
    } else {
        double V_corr = sqrt(2.0 * diff_corr / rho);
        cout << "Critical velocity: " << V_corr << " m/s\n";
    }
    return 0;
}