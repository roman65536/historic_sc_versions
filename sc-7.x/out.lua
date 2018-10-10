#!/usr/bin/lua

file=io.open("test.xml", "w+")

while true do
 line=io.read()
 if line == nil then break end

 file:write(line)
end

file:close()






