close all
radius = 5.4;
num_find = 19;
threshold = 155;

im = imread('img/rowrowbt_mod3.png');
row_notes = extract_notes(im, threshold, num_find, radius);

im = imread('img/lond_mod2.jpg');
lond_notes = extract_notes(im, threshold, num_find, radius);