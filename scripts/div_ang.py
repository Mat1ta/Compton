import numpy as np
import matplotlib.pylab as plt
from scipy.optimize import curve_fit

theta, entries, time,f= np.loadtxt('../dati/div_ang.txt', unpack=True)
f=entries/time

df=(1/(time*np.sqrt(12))+(1/np.sqrt(entries)))*f
dt=1/np.sqrt(12)*np.array([1,1,1,1,1,1,1,1,1,1])


plt.errorbar(theta, f, df, dt,   fmt='.b', label='data')


def gaus(x, u, s, A):
	return A*np.exp(-(x-u)**2/s**2)

par=[-1, 3, 9000]
xx=np.linspace(-5, 15, 1000)

popt, pcov = curve_fit(gaus, theta, f, sigma=df)
deff= df + (2*popt[2]*np.exp(-(theta-popt[0])**2/popt[1]**2)*(theta-popt[0])/popt[1]**2)*dt
popt, pcov = curve_fit(gaus, theta, f, sigma=deff)
deff= df + (2*popt[2]*np.exp(-(theta-popt[0])**2/popt[1]**2)*(theta-popt[0])/popt[1]**2)*dt
popt, pcov = curve_fit(gaus, theta, f, sigma=deff)

plt.plot(xx, gaus(xx, *popt), color='red', label='fit')
plt.title('Angular divergence')
plt.xlabel('$\\theta$ [$\\degree$]')
plt.ylabel('f [Hz]')
plt.text(7, 6500, f'Fit result:\nA={popt[2]:.0f}$\pm${np.sqrt(pcov[2][2]):.0f}\n $\mu$={popt[0]:.2f}$\pm${np.sqrt(pcov[0][0]):.2f}\n  $\sigma$={popt[1]:.2f}$\pm${np.sqrt(pcov[1][1]):.2f}', size= 'large')
plt.legend(loc='lower left')
print(popt, pcov)
r = f - gaus(theta, *popt)
chisq = sum((r / df) ** 2)
print(chisq)
print(f'la media di questa gaussiana è u={popt[0]} +- {np.sqrt(pcov[0][0])}')

plt.savefig('../plots/div_ang.pdf')
plt.show()