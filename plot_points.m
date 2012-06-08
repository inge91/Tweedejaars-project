
% coord_list is a list of horizontal vectors,
% all consisting of a x, y and z coordinate
function plot_points(coord_list)

% all lists needed to implement th
x_list = [];
y_list = [];
z_list = [];


% for all the coordinate points in the list 
for i = 1:4:length(coord_list)
    x_list = [x_list; coord_list(i)];
    y_list = [y_list; coord_list(i+1)];
    z_list = [z_list; coord_list(i+2)];
end

min_value = min(coord_list);
max_value = max(coord_list);
min_value = min_value - 20;
max_value = max_value + 20;

hold on
plot3([x_list], [y_list], [z_list])
axis([min_value max_value min_value max_value min_value max_value]) 
xlabel('x')
ylabel('y')
zlabel('z')

pause

