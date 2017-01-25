f = 0:10:20000;
omega = 2*pi*f;
num =[1.0341377989688962 -1.905126709686432 0.8972615950291296];
den =[1 -1.905126709686432 0.931399393998026];

opts = bodeoptions;
opts.FreqUnits = 'Hz';
[h, f] = freqz(num, den, 512, 44100);
abs(h)
semilogx(f, 20*log10(abs(h))), grid;

axis([0 22000 -12 12]);
title ('Biquad Filter');
xlabel ('Frequency (Hz)');
ylabel ('Magnitude (dB)');


