#include <iostream>
#include <cmath>
using namespace std;

double N(double x) {
    return 0.5 * (1 + erf(x / sqrt(2)));
}

double blackScholes(double S, double K, double T, double r, double sigma, char type) {
    double d1 = (log(S / K) + (r + (pow(sigma, 2) / 2)) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);

    if (type == 'c') {
        return S * N(d1) - K * exp(-r * T) * N(d2);
    } else if (type == 'p') {
        return K * exp(-r * T) * N(-d2) - S * N(-d1);
    } else {
        throw invalid_argument("Type d'option invalide. Utilisez 'c' pour un call ou 'p' pour un put.");
    }
}

int main() {
    double S, K, T, r, sigma;
    char type;

    cout << "Prix de l'actif sous-jacent (S) : ";
    cin >> S;
    cout << "Prix d'exercice (K) : ";
    cin >> K;
    cout << "Temps jusqu'à l'échéance (T) : ";
    cin >> T;
    cout << "Volatilité (sigma) : ";
    cin >> sigma;
    cout << "Taux sans risque (r) : ";
    cin >> r;
    cout << "Type d'option (c pour call, p pour put) : ";
    cin >> type;

    try {
        double prixOption = blackScholes(S, K, T, r, sigma, type);
        cout << "Le prix de l'option est : " << prixOption << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}
