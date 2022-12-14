#include "LL.h"
#include "Timer.h"

#include <iostream>
#include <map>
#include <random>

/**
 * @brief Appends a node with value i to the list
 *
 * @param i value for node
 * @return false if cycle already created
 */
bool LL::append(unsigned int i) {
  if (tail && tail->next) {  // is there already a cycle?
    return false;
  }

  Node *n = new Node(i);
  if (tail == nullptr) {  // empty list
    head = tail = n;
    num_nodes++;
    return true;
  }
  tail->next = n;
  tail = n;

  num_nodes++;

  return true;
}

/**
 * @brief
 * ascending values
 *
 * @param n number of nodes
 */
void LL::append_n_nodes_ascending(unsigned int n) {
  for (unsigned int i = 0; i < n; ++i) {
    append(i);
  }
}

/**
 * @brief Appends n nodes to the list with random
 * values from 0-range
 *
 * @param n number of nodes
 * @param range range of random values
 */
void LL::append_n_nodes_random(unsigned int n, unsigned int range) {
  unsigned int r;

  for (unsigned int i = 0; i < n; ++i) {
    r = rand() % range;
    append(r);
  }
}

/**
 * @brief Creates a cycle by setting tail->next
 * to the ith node in the list. If there are
 * fewer than i nodes in the list, the operation
 * does not mutate the list
 *
 * @param i the node position which the tail
 * should be linked to. Defualt value of 0
 * indicates head node.
 *
 * @return True if operation successful, False otherwise
 *
 */
bool LL::create_cycle(unsigned int i) {
  if (i > num_nodes) {
    return false;
  }  // too high
  if (head == nullptr) {
    return false;
  }  // empty list, can't create a cycle

  Node *ith_node = head;

  for (unsigned int j = 0; j < i; ++j) {
    ith_node = ith_node->next;
  }

  tail->next = ith_node;
  return true;
}

/**
 * @brief Prints the contents of list in
 * following format:
 *
 * 1-> 2-> 3-> ... m-> n
 *
 */
void LL::print_list() {
  if (head == nullptr) {
    std::cout << "Empty List" << std::endl;
    return;
  }

  Node *next;
  Node *current = head;

  // only way to know we're at 'end' of list
  // is to hit tail. Can't depend on nullptr
  // because of possible cycle
  while (current != tail) {
    std::cout << current->value << "-> ";
    current = current->next;
  }

  print_last_node(current);
}

/**
 * @brief Prints the beginning of the list
 * up until index i, and then from j to the end
 *
 * @param i index to print to
 * @param j index to print from until end

 * @return true if indexes were valid, false otherwise
 */
bool LL::print_partial_list(unsigned int i, unsigned int j) {
  if (j < i) {
    return false;
  }  // invalid
  if (j > num_nodes || i > num_nodes) {
    return false;
  }                                 // invalid
  if (i == j || head == nullptr) {  // i == j is just the regular list
    print_list();
    return true;
  }

  Node *n = head;
  bool do_once = true;

  for (int l = 0; l < num_nodes; ++l) {
    if (l == num_nodes - 1) {
      // handles last node
      print_last_node(n);
    } else if (l < i) {
      std::cout << n->value << "-> ";
    } else if (l > j) {
      std::cout << n->value << "-> ";
    } else if (do_once) {
      std::cout << "...-> ";
      do_once = false;
    }
    // advance node
    n = n->next;
  }

  return true;
}

/**
 * @brief handles printing the last node of the
 * linked list. We may want to include an indication
 * that there is a cycle, but that depends on
 * whether or not there is a cycle.
 *
 * @param last the last node
 */
void LL::print_last_node(Node *last) {
  if (last->next != nullptr) {
    std::cout << last->value << "->[cycle]-> ";
    std::cout << last->next->value << "-> ..." << std::endl;
  } else
    std::cout << last->value << std::endl;
}

/**
 * @brief Performs cycle detection using linear search on the LL. By keeping
 * record of visited nodes with hashmap, at each node we check if it has been
 * visited before. If it has, we know there is a cycle. If not, we add it to the
 * hashmap and continue. If we reach the end of the list, we know there is no
 * cycle.
 *
 * @return true if cycle detected
 * @return false if no cycle detected
 **/
bool LL::linear_cycle_detection() {
  // empty list
  if (head == nullptr) {
    return false;
  }

  std::map<Node *, bool> visited;  // map of visited nodes
  Node *current = head;

  while (current->next != nullptr) {
    if (visited[current]) {
      // cycle detected
      return true;
    }
    visited[current] = true;
    current = current->next;  // advance
  }

  return false;
}

/**
 * @brief Performs cycle detection using linear search on the LL. At each
 * node, the visited flag is checked.
 * If it has been visited, we know there is a cycle. If not, we and continue.
 * If we reach the end of the list, we know there is no cycle.
 *
 * @return true if cycle detected
 * @return false if no cycle detected
 **/
bool LL::linear_cycle_detection_no_map()
{
  // empty list
  if (head == nullptr)
  {
    return false;
  }
  Node *current = head;

  while (current->next != nullptr)
  {
    if (current->visited)
    {
      // cycle detected
      return true;
    }
    current->visit();
    current = current->next; // advance
  }

  return false;
}

/**
 * @brief Performs Floyd's cycle detection
 * algorithm on the linked list
 *
 * for the purposes of this algorithm, we assume
 * that there is no tail pointer
 *
 * @return true if there is a cycle
 * @return false if there is no cycle
 */
bool LL::floyd_cycle_detection() {
  if (head == nullptr) {
    return false;
  }  // empty list
  if (head->next == head) {
    return true;
  }  // single item list

  Node *traversal_1 = head;
  Node *traversal_2 = head;

  while (traversal_1 && traversal_2 && traversal_2->next) {
    // advance "tortoise" by 1
    advance(traversal_1);
    // advance "hare"
    advance(traversal_2);
    advance(traversal_2);

    if (traversal_1 == traversal_2) {  // cycle detected
      return true;
    }
  }

  // cycle not detected, because the end of the linked
  // list points to nullptr.
  return false;
}

/**
* @brief Performs Brent's cycle detection
* algorithm on the linked list
*
* @return true if there is a cycle
* @return false if there is no cycle
*/
bool LL::brent_cycle_detection(){
  if (head == nullptr || head->next == nullptr) {
    return false;
  }  // empty list or single element


  Node *tortoise = head;
  Node *hare = tortoise->next;

  unsigned int hare_traversal_speed = 1;
  unsigned int cycle_length = 1;

  while(hare != nullptr){
    if(hare == tortoise){
      return true;
    }
    if(cycle_length == hare_traversal_speed){
      tortoise = hare;
      cycle_length = 0;
      hare_traversal_speed = hare_traversal_speed*2;
    }
    advance(hare);
    cycle_length++;
  }
  return false;
}

/**
 * @brief advances a node down the linked list
 *
 * @param node pointer to node to advance
 * @return false if node is nullptr
 */
bool LL::advance(Node *&node) {
  if (node) {
    node = node->next;
    return true;
  }
  return false;
}

/**
 * @brief Handles all the detection
 * and boolean conversion and printing
 * for you
 *
 * @param alg which alg you want to use
 * 1 : linear
 * 2 : floyd
 * 3 : brent
 */
void LL::do_cycle_detection(int alg){
  bool cycle_found = false;
  std::string alg_string;
  double elapsed;

  if(alg == 1){
    alg_string = "Linear Cycle Detection";
    auto t = start_timer();
    cycle_found = linear_cycle_detection();
    elapsed = end_timer(t);
  }
  else if(alg == 2){
    alg_string = "Floyd's Cycle Detection";
    auto t = start_timer();
    cycle_found = floyd_cycle_detection();
    elapsed = end_timer(t);
  }
  else if(alg == 3){
    alg_string = "Brent's Cycle Detection";
    auto t = start_timer();
    cycle_found = brent_cycle_detection();
    elapsed = end_timer(t);
  }
  else if (alg == 4)
  {
    alg_string = "Linear Cycle Detection (No Map)";
    auto t = start_timer();
    cycle_found = linear_cycle_detection_no_map();
    elapsed = end_timer(t);
  }
  else {return;}


  std::string l1_cycle = (cycle_found ? "True" : "False");
  std::cout << "-----------------------------------" << std::endl;
  std::cout << "Algorithm: " << alg_string << std::endl;
  // handles printing list
  if(num_nodes < 10){
    print_list();
  }
  else{
    print_partial_list(5, num_nodes-5);
  }
  std::cout << "Cycle found: " << l1_cycle << std::endl;
  std::cout << "Elapsed time: " << elapsed << " seconds" << std::endl;
  std::cout << "-----------------------------------" << std::endl;

}

LL::~LL() {
  if (head == nullptr) {
    return;
  }  // empty list

  Node *next;
  Node *current = head;

  // only way to know we're at 'end' of list
  // is to hit tail. Can't depend on nullptr
  // because of possible cycle
  while (current != tail) {
    next = current->next;
    delete current;
    current = next;
  }

  delete current;  // delete the last one
}
