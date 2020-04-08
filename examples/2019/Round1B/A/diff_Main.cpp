diff --git a/CodeJam/Main.cpp b/examples/2019/Round1B/A/Main.cpp
index 1b5e28b..01a3490 100644
--- a/CodeJam/Main.cpp
+++ b/examples/2019/Round1B/A/Main.cpp
@@ -4,7 +4,7 @@
 // #define IA_MODE        //remove comment on this line, to activate interactive problem mode
 #define IA_ERROR_CODE "ERROR"
 // #define XY_NOTATION    //remove commment on this line, to activate xy notation on complex numbers
-#define COMM_TYPE ll
+#define COMM_TYPE str
 
 // The maintained and empty code template can be found at:
 // https://github.com/DavidS3141/CodeJamTemplate
@@ -828,11 +828,59 @@ namespace task {
 void init(){
 }
 
+ll P, Q;
+v(cell) persons;
+v(cell) directions;
+v(char) dirnames;
+d(ll, ll) xcounts;
+d(ll, ll) ycounts;
+
 void readInput(){
+    cin >> P >> Q;
+    xcounts.clear();
+    ycounts.clear();
+    persons.clear();
+    directions.clear();
+    dirnames.clear();
+    forn(i, P){
+        ll xi, yi;
+        char dir;
+        cin >> xi >> yi >> dir;
+        persons.pb(cell(xi, yi));
+        directions.pb(DIRECTIONS[dir]);
+        dirnames.pb(dir);
+        if(dir == 'N'){
+            ycounts[yi+1]++;
+        } else if(dir == 'S'){
+            ycounts[yi]--;
+        } else if(dir == 'E'){
+            xcounts[xi + 1]++;
+        } else if(dir == 'W'){
+            xcounts[xi]--;
+        } else {
+            lassert(false, "logic error");
+        }
+    }
 }
 
 // write to COMM_TYPE result
 void calcFunction() {
+    ll bestx=0, besty=0, cx=0, cy=0, bestcx=0, bestcy=0;
+    foreach(it, xcounts){
+        cx += it->nd;
+        if(cx > bestcx){
+            bestx = it->st;
+            bestcx = cx;
+        }
+    }
+    foreach(it, ycounts){
+        cy += it->nd;
+        if(cy > bestcy){
+            besty = it->st;
+            bestcy = cy;
+        }
+    }
+    result = to_string(bestx) + " " + to_string(besty);
 }
 
 } // namespace task
