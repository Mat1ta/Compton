# Script to evaluate the energy [MeV] starting from energy [a.u.] (named b)
# and (m, q) from the calibration fit. The equations are for central value:
#   E [MeV] = (b - q) / m
#   deltaE [MeV] = sqrt((db^2 + dq^2)/m^2 + (b^2dm^2)/m^4 + (2bc)/m^3)
# Where c is Cov(m,q), the covariance term between m and q.

import numpy as np

def central(b, m, q):
    return (b - q) / m

def stat(b, db, m, dm, q, dq, c):
    a_1 = (db**2 + dq**2) / m**2
    a_2 = (b**2 * dm**2) / m**4
    a_3 = (2 * b * c) / m**3
    return np.sqrt(a_1 + a_2 + a_3)

def sist(db, m):
    return np.sqrt(db**2 / m**2)

if __name__ == '__main__':
    b = 4743
    db = 8
    b_sist = 81
    m = 4887
    dm = 37
    q = 195
    dq = 37
    c = -1305
    print(f'{central(b, m, q):.4f} +/- {stat(b, db, m, dm, q, dq, c):.4f} stat +/- {sist(b_sist, m):.4f} sist')
