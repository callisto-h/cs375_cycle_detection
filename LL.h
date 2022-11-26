#ifndef LL_H
#define LL_H

class LL {
 private:
  class Node {
   public:
    unsigned int value;
    Node *next;
    Node() {
      value = 0;
      next = nullptr;
    }
    Node(unsigned int i) {
      value = i;
      next = nullptr;
    }
  };

  // LL member variables
  Node *head;
  Node *tail;
  unsigned int num_nodes;

 public:
  LL() {
    head = tail = nullptr;
    num_nodes = 0;
  }
  /**
   * @brief Appends a node with value i to the list
   *
   * @param i value for node
   * @return false if cycle already created
   */
  bool append(unsigned int i);

  /**
   * @brief Appends n nodes to the list with
   * ascending values
   *
   * @param n number of nodes
   */
  void append_n_nodes_ascending(unsigned int n);

  /**
   * @brief Appends n nodes to the list with random
   * values from 0-range
   *
   * @param n number of nodes
   * @param range range of random values
   */
  void append_n_nodes_random(unsigned int n, unsigned int range);

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
  bool create_cycle(unsigned int i = 0);

  /**
   * @brief Prints the contents of list in
   * following format:
   *
   * 1-> 2-> 3-> ... m-> n
   *
   */
  void print_list();

  /**
   * @brief Prints the beginning of the list
   * up until index i, and then from j to the end
   *
   * @param i index to print to
   * @param j index to print from until end
   * @return true if indexes were valid, false otherwise
   */
  bool print_partial_list(unsigned int i, unsigned int j);

  /**
   * @brief handles printing the last node of the
   * linked list. We may want to include an indication
   * that there is a cycle, but that depends on
   * whether or not there is a cycle.
   *
   * @param last the last node
   */
  void print_last_node(Node *last);

  /**
   * @brief Performs linear cycle detection on the list by keeping record
   *of visited nodes with hashmap.
   *
   * @return true if cycle detected
   * @return false if no cycle detected
   **/
  bool linear_cycle_detection();

  /**
   * @brief Performs Floyd's cycle detection
   * algorithm on the linked list
   *
   * @return true if there is a cycle
   * @return false if there is no cycle
   */
  bool floyd_cycle_detection();

  /**
  * @brief Performs Brent's cycle detection
  * algorithmm on the linked list
  * 
  * @return true if there is a cycle
  * @return false if there is no cycle 
  */
  bool brent_cycle_detection();

  /**
   * @brief advances a node down the linked list
   *
   * @param node pointer to node to advance
   * @return false if node is nullptr
   */
  bool advance(Node *&node);

  ~LL();
};

#endif