close all;

threshold = 5; %check 5 vs. 200 lol
% radius = 10; %pretty good for 4th, 8th... change for whole notes I guess
% num = 50; %ehhhh

%egg = imread('egg.jpg');
%jup = imread('jupiter.jpg');
hcb = imread('hcb-1.jpg');
rrb = imread('rowrowbt_mod2.png');

% radius = 9; 
% num = 3;
% edges = detectEdges(egg, threshold, 1);
% centers = detectCircles(egg, edges, radius, num, 1);
% 
% radius = 110; 
% num = 1; 
% edges = detectEdges(jup, threshold, 0);
% centers = detectCircles(jup, edges, radius, num, 1);
% 
% pause;
%
radius = 10; %pretty good for 4th, 8th
num = 50; 
edges = detectEdges(hcb, threshold, 0);
centers = detectCircles(hcb, edges, radius, num, 6/19);

radius = 7; %pretty good for 4th, 8th
num = 30; 
edges = detectEdges(rrb, threshold, 0);
centers = detectCircles(rrb, edges, radius, num, 7/27);