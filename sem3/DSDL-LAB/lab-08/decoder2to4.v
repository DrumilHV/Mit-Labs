module dec2to4(en,w,y);
input en;
input [1:0]w;
input [3:0]y;
output reg [3:0]y;
always @(en,w) 
begin
    if(en==0)
    y=0;
    else
    begin
      if(w==0)
      y=0;
      elseif(w==1)
      y=2;
      elseif(w==2)
      y=4;
      else
      y=8;
    end    
end
endmodule