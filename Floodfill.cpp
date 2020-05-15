#include <array>
#include <iostream>
#include <list>
#include <map>
#include <tuple>
#include <vector>
struct point {
  int x;
  int y;
};

bool operator<(const point& lhs, const point& rhs){
  return std::tie(lhs.x, lhs.y) < std::tie(rhs.x, rhs.y);
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

void print_path(const std::list<point>& path);

void print_map(world& map);

int main(){

  //Skapa kartan
  world map = {
    {1, 1, 1, 1, 1, 1, 1, 1,
     1, 0, 0, 0, 0, 0, 0, 1,
     1, 0, 0, 1, 1, 1, 0, 1,
     1, 0, 0, 1, 0, 0, 0, 1,
     1, 0, 0, 1, 0, 0, 0, 1,
     1, 0, 0, 1, 0, 0, 0, 1,
     1, 0, 0, 0, 0, 0, 0, 1,
     1, 1, 1, 1, 1, 1, 1, 1}
  };
//{y,x} <-----------
  //Hitta en väg från {1,1} till {4,4}
  auto path = get_path({1,1}, {4,4}, map);

  //Skriv ut hela vägen
    std::cout << path.size();
  print_path(path);

  print_map(map);

  //Kontrollera att den faktiskt tar dig från start till slut.
  return validate_path(path, map) ? 0 : 1;
}

std::list<point> get_path(const point& start, const point& goal, world& map){
  std::list<point> path;

point current_node = start;
//point new_node = map
point end_node = goal;
world mapsize;

std::vector<point> grannar = {point{0, 1}, point{0, -1}, point{1, 0}, point{-1, 0}};
std::map<point, point> visited_nodes{};
//std::vector<point> grannar = {point{start.y, start.x+1}, point{start.y, start.x-1}, point{start.y+1, start.x}, point{start.y-1, start.x}};

std::vector<point> search_nodes{};
  //Todo: Implement this :)
    while(current_node.x != end_node.x || current_node.y != end_node.y){
        for(const auto& pt : grannar){//LOOPAT IGENOM ALLA GRANNAR
                point neighbour{};
                neighbour.x = pt.x + current_node.x;
                neighbour.y = pt.y + current_node.y;
            if(neighbour.x >= 0 && neighbour.x < map_width && neighbour.y >= 0 && neighbour.y < map_height && map[neighbour.y][neighbour.x] == 0)
            {
                //neighbour.x = pt.x + current_node.x;
                //neighbour.y = pt.y + current_node.y;

                if(visited_nodes.find(neighbour) == std::end(visited_nodes))
                {
                    search_nodes.push_back(neighbour);
                    visited_nodes[neighbour] = current_node;



                }

                std::cout << search_nodes.size() << std::endl;
                std::cout << visited_nodes.size() << std::endl;
                std::cout << "\n(" << map[neighbour.x][neighbour.y] <<")";
                std::cout <<"---------------------------------\n";
            }

}

    auto next_node = search_nodes.back();
    current_node.x = next_node.x;
    current_node.y = next_node.y;
    search_nodes.pop_back();
}
    std::cout << visited_nodes.size() << std::endl;
    while(current_node.x != start.x || current_node.y != start.y){
        path.push_front(current_node);
        current_node = visited_nodes[current_node];
    }

  return path;
}

bool validate_path(std::list<point> path, const world& map) {
  //Todo: Låt Mikael skriva den här...

  return path.size() > 0;
}

void print_path(const std::list<point>& path) {
  for(const auto& p : path) {
    std::cout << "(" << p.x << " : " << p.y << ")" << std::endl;
  }
}
void print_map(world& map) {
  for(int i = 0; i < map_height; i++){
    for(int j = 0; j < map_width; j++){
      std::cout << map[i][j] << " ";
    }
    std::cout << "\n";
  }
}



