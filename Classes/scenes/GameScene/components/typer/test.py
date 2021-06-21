s= "is transported by boats through seas, rivers, lakes, and canals. Large quantities of water, ice, and steam are used for cooling and heating, in industry and homes. Water is an excellent solvent for a wide variety of substances both mineral and organic; as such it is widely used in industrial processes, and in cooking and washing. Water, ice and snow are also central to many sports and other forms of entertainment, such as swimming, pleasure boating, boat racing, surfing, sport fishing, diving, ice skating and skiing"
s = s.lower()
abc = "abcdefghijklmnopqrstuvwxyz"

res = "\""
for char in s:
    if char in abc:
        res = res + char
    if char == " ":
        res = res + "\", \""
print(res)