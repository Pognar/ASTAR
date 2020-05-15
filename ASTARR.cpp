#include <array>
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <tuple>
#include <vector>
#include <queue>
#include <math.h>

struct point {
  int x;
  int y;
};

bool operator<(const point& lhs, const point& rhs){
  return std::tie(lhs.x, lhs.y) < std::tie(rhs.x, rhs.y);
}
bool operator==(const point& lhs, const point& rhs){
  return lhs.x == rhs.x && lhs.y == rhs.y;
}
bool operator!=(const point& lhs, const point& rhs){
  return !(lhs == rhs);
}
point operator+(const point& lhs, const point& rhs){
  point ret;
  ret.x = lhs.x + rhs.x;
  ret.y = lhs.y + rhs.y;
  return ret;
}

const int map_width  = 8;
const int map_height = 8;

struct world {
  int map_[map_height*map_width];
  const auto operator[](int r){ return map_ + r*map_width; }
};

//int world[map_height][map_width];

std::list<point> get_path(const point& start, const point& goal, world& map);
//if(pt.x !=1 && pt.y !=1
bool validate_path(std::list<point> path, const world& map);

bool isValid(const point& pt);

bool isWall(const point& pt, world& map);

void print_node(const point& pt);

void print_path(const std::list<point>& path);

void print_map(world& map);

double distance_cost(point a, point b);

int main(){

  /* Skapa kartan
     NOTE: Jag bytte betydelse mellan vägg och golv...
     Golv är nu 1 och vägg är 0.
     Anledningen till det var för att logiken skulle se lite snyggare
     ut med kostnaderna för noderna.
     Om en nod har ett värde > 1 betyder det att det är någon form av
     terräng, ex. en kulle.
   */
  world map = {
    {0, 0, 0, 0, 0, 0, 0, 0,
     0, 1, 1, 1, 1, 1, 1, 0,
     0, 1, 2, 2, 2, 1, 1, 0,
     0, 1, 2, 3, 2, 1, 1, 0,
     0, 1, 2, 2, 2, 1, 1, 0,
     0, 1, 1, 1, 1, 1, 1, 0,
     0, 1, 1, 1, 1, 1, 1, 0,
     0, 0, 0, 0, 0, 0, 0, 0}
  };
  //Hitta en väg från {1,1} till {5,5}

  auto path = get_path({1,1}, {5,5}, map);

  //Skriv ut hela vägen
  print_path(path);

  print_map(map);

  //Kontrollera att den faktiskt tar dig från start till slut.
  return validate_path(path, map) ? 0 : 1;
}

std::list<point> get_path(const point& start, const point& goal, world& map){
  std::list<point> path;

  point current_node = start;
  point end_node = goal;
  int current_cost = map[start.y][start.x];

  std::vector<point> grannar = {point{0, 1}, point{0, -1}, point{1, 0}, point{-1, 0}};
  std::map<point, point> visited_nodes{};
  
  //std::vector<point> search_nodes{};


    auto cmp = [](const std::tuple<double, point>& lhs, const std::tuple<double, point>& rhs){
      return std::get<double>(lhs) > std::get<double>(rhs);
    };
    std::priority_queue<std::tuple<double, point>, std::vector<std::tuple<double, point>>, decltype(cmp)> search_nodes(cmp);

  while(current_node != end_node){
    for(const auto& pt : grannar){
      point neighbour = pt + current_node;
      if(isValid(neighbour) && !isWall(neighbour, map)) {
        if(visited_nodes.find(neighbour) == std::end(visited_nodes)) {
	  double cost = map[neighbour.y][neighbour.x] + current_cost + distance_cost(neighbour, end_node);
          search_nodes.push(std::make_tuple(cost,neighbour));
          visited_nodes[neighbour] = current_node;
        }
      }
    }
  
    if(!search_nodes.empty() && current_node != end_node){

      current_node = std::get<point>(search_nodes.top());
      current_cost = std::get<double>(search_nodes.top());
	search_nodes.pop();
    } 
  }

  while(current_node != start){
    path.push_front(current_node);
    current_node = visited_nodes[current_node];
  }
  path.push_front(start);

  return path;
}

bool validate_path(std::list<point> path, const world& map) {
  //Todo: Låt Mikael skriva den här...

  return path.size() > 0;
}

bool isValid(const point& pt) {
  return (pt.x >= 0 && pt.x < map_width) && (pt.y >= 0 && pt.y < map_height);
}

bool isWall(const point& pt, world& map){
  return map[pt.y][pt.x] == 0;
}

void print_path(const std::list<point>& path) {
  for(const auto& p : path) {
    std::cout << p.x << " : " << p.y << "\n";
  }
}
double distance_cost(point neighbour, point end_node){
	double xled = neighbour.x - end_node.x;
	double yled = neighbour.y - end_node.y;
	double resultat = std::sqrt(std::pow(xled,2) + std::pow(yled,2));
  return resultat;
	

}

void print_node(const point& pt){
    std::cout << "(" << pt.x << " : " << pt.y << ")" << "\n";
}

void print_map(world& map) {
  for(int i = 0; i < map_height; i++){
    for(int j = 0; j < map_width; j++){
      std::cout << map[i][j] << " ";
    }
    std::cout << "\n";
  }
}



