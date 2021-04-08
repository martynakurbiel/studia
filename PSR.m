xc = 40; yc = 95;
for x=-100:1:100
    for y=-100:1:100
        z(x+101,y+101)=200./((x-xc).^2 + (y-yc).^2 + 200);
    end
end
x=-100:1:100;
y=-100:1:100;
surf(x,y,z)
hold on 
xc = 20; yc = 10;
for x=-100:1:100
    for y=-100:1:100
        z(x+101,y+101)=200./((x-xc).^2 + (y-yc).^2 + 200);
    end
end
x=-100:1:100;
y=-100:1:100;
surf(x,y,z)

 sl_braitenberg