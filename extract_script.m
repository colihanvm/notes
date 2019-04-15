close all
%set input values
radius = 5.4;
num_find = 19;
threshold = 155;

%read notes from different sheets of music
im = imread('img/rowrowbt_mod3.png');
row_notes = extract_notes(im, threshold, num_find, radius);

im = imread('img/lond_mod2.jpg');
lond_notes = extract_notes(im, threshold, num_find, radius);

%write to a .txt file
% f = fopen('test1.txt', 'w');
% formatSpec = '%c%c\n';
% fprintf(f, formatSpec, lond_notes');

%write to phone
% s = serial('cu.usbmodem1411');
% s = fopen(s);
% formatSpec = '%c%c\n';
% fprintf(s, formatSpec, lond_notes');
% fclose(s);

s = serial('cu.usbmodem1411');
fopen(s);
fprintf(s, '*IDN?');
idn = fscanf(s);
fclose(s);