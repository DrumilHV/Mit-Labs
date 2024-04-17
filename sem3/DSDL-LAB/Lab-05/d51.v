module d51(en,w,y);
input [1:0]en,w;
output reg [3:0]y;
always @(en,w) 
begin
    if(en==0)
    y=0;
    else
    begin
      if(w==0)
      y=1;
      else if(w==1)
      y=2;
      else if(w==2)
      y=4;
      else
      y=8;
    end    
end
endmodule