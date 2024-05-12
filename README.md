<-- // by Yehuda Avraham 325550069 mail: yehudav03@gmail.com -->

# גרפים ואלגוריתמים

## סקירה

אלגוריתמים עבור גרפים הם קבוצת אלגוריתמים שמתמקדים בפתרון בעיות שונות הנוגעות לגרפים. גרף הוא מבנה נתונים המיועד לייצוג יחסים בין עצמים. גרף מורכב מקבוצת קודקודים וקשתות המקשרות ביניהם. קיימים סוגים שונים של גרפים, כגון גרפים מכוונים ולא מכוונים, גרפים ממשוקלים ולא ממושקלים , בעלי מעגלים או נטולי מעגלים ובעלי צלעות שלילות או צלעות חיוביות בלבד .

## מחלקות עיקריות

### גרף - Graph

מחלקה המייצגת גרף ע"י מטריצת שכנויות , מייצגת את כל סוגי הגרפים בין ממשוקלים למכוונים ולא מכוונים. כולל משקלים שליליים.
המחלקה מאפשרת לטעון גרף חדש , לקבל את מטריצת השכנויות של הגרף , לקבל את המשקלים של הצלעות , גודל הגרף ולהדפיס אותו.

### אלגוריתמים - Algorithms

מחלקה עיקרית של כל האלגוריתמים המבוצעים על הגרף , כוללת את הפונקציות הבאות:

```cpp
static bool isConnected(const ariel::Graph &g);
//בודקת האם גרף הוא גרף מקושר.


static string shortestPath(const ariel::Graph &g, int src, int dest);
//מחזירה את המסלול הקצר ביותר בין קודקוד המקור לקודקוד היעד אם קיים מסלול אחרת מחזירה
"1-".

static string isContainsCycle(const ariel::Graph &g);
//בודקת האם קיים מעגל בגרף אם כן מחזירה את המעגל.

static string isBipartite(const ariel::Graph &g);
//בודקת האם הגרף הוא גרף דו צבעי אם כן מחזירה את הצביעה אחרת מחזירה "1-".

static bool negativeCycle(const ariel::Graph &g);
// בודקת האם קיים מעגל שלילי בגרף מחזירה שקר או אמת.
```

## פונקציות ומערכי עזר

```cpp
        static vector<vector<int>> adj; // Adjacency matrix
        static vector<int> color; // Vector to mark colors on Bipartite graph check
        static vector<int> parent; // Vector to mark parents on cycle check and shortest path
        static vector<bool> visited;// Vector to mark visited nodes
        static vector<bool> recStack;
        // vector to save next nodes to be visited in DFS
        static vector<int> dist;
        // Vector to save distances from source node
        static queue<int> q;
        // Queue for BFS

        static string shortestPathUnweighted(int source, int destination);
        // Dijkstra's algorithm for shortest path using dfs
        static string dijkstra(int source, int destination);
        // Bellman-Ford algorithm for shortest path using ralaxation
        static string bellmanFord(int source, int destination , int type);
        // Util function for checking if the graph contains a cycle using DFS
        static string isCyclicUtil(int v, int parent);
        // Check if the graph contains a cycle using DFS and back edges
        static string checkDirectedCycle();
        // Check if the graph contains a cycle using DFS and back edges for undirected graph
        static string checkUndirectedCycle();
        // Util function for checking if the graph contains a cycle using DFS
        static bool checkDirectedCycleUtil(int v);
        // Util function for checking if the graph contains a cycle using DFS
        static bool checkUndirectedCycleUtil(size_t v, int parent_of_v);
        // Construct the cycle path
        static string constructCyclePath(int cycle_start, int cycle_end, int type);
        // print the adjacency matrix
        static void print_adj_mat(const vector<vector<int>> &adj);

```

## מימוש

המימוש נעשה בהתחשב בסוגי גרפים שונים ותומך בגרפים מכוונים\לא מכוונים , ממושקלים\לא ממושקלים , בעלי צלעות חיוביות ושליליות , בעלי מעגלים ונטולי מעגלים.

במימוש נעשה שימוש באלגוריתמים כגון דיקסטרה , BFS, DFS, בלמן-פורד , ובדיקות שונות כגון בדיקת מעגלים , בדיקת צביעה לגרף דו צבעי, חישוב מסלול קצר ביותר ובדיקת קשירות.

בנוסף נעשה שימוש במערכי עזר כגון וקטורים ומטריצות על מנת לשמור על נתונים ולבצע חישובים.

### תהליך המימוש

ביצירת גרף חדש אנו טוענים את מטריצת השכנויות ע"י השימוש בפונקציה loadGraph מוודאים כי הגודל שלה אכן תקין והיא הינה מטריצה ריבועית. לאחר מכן אנו עוברים על כל צלעות הגרף ומוודאים איזה סוג של גרף הגרף הנתון.  
בדיקה זו מתבצעת ע"י כמה סוגים של בדיקות בדיקה אם קיימת צלע שלילית האם משקל הצלעות ה [I][J] , [J][I] שווה על מנת לבדוק האם הגרף מכוון או לא , וכן בדיקה משקלי הגרף לוודא כי הגרף ממושקל או לא.

לאחר טעינת הגרף אנו מבצעים את הפונקציות השונות על הגרף כגון בדיקת קשירות , בדיקת מעגלים , חישוב מסלול קצר ביותר ובדיקת צביעה לגרף דו צבעי.

### מימוש פונקציות

- isBipartite:  
  הפונקציה מתחילה על ידי בדיקה של כל הצמתים בגרף באמצעות BFS.
  היא מציירת צבעים לצמתים (0 או 1) כך שצמתים המקושרים לצמת נתון מקבלים צבע שונה.
  היא משתמשת בתור עזר ובקבוצות A ו-B על מנת לשמור על הצמתים בכל חלק של הגרף.
  בסיום הבדיקה, היא בודקת אם קיימים צמתים שלא צבועים. אם כן, הגרף אינו דו-חלקי.

- isConnected:  
  אם הגרף מכוון, הפונקציה מבצעת DFS באמצעות ערימה כדי לבדוק האם הגרף קשור.
  אם הגרף לא מכוון, הפונקציה מבצעת BFS.
  בסיום התהליך, היא בודקת אם יש צמתים שלא נגישים. אם כן, הגרף אינו קשור.
- shortestPath:  
  הפונקציה מתחילה על ידי בדיקת תקינות הצמתים.
  אם הצמתים תקינים, היא בודקת את סוג הגרף (ממושקל, לא ממושקל, עם מסלולים שליליים) ומשתמשת באלגוריתמים הרצויים (Dijkstra או Bellman-Ford) כדי למצוא את המסלול הקצר ביותר.
- isContainsCycle:  
  הפונקציה מתחילה על ידי בדיקה של מעגלים אפשריים בגרף.
  אם הגרף מכיל מעגלים, היא מזהה אותם ומחזירה את המעגל הנמצא.
- negativeCycle:  
  הפונקציה בודקת האם קיים מעגל שלילי בגרף.  
  היא משתמשת ב-"Bellman-Ford" ומחזירה הודעה על פי התוצאה.

  ***
