/* \author Aaron Brown */
// Quiz on implementing kd tree

#include "../../render/render.h"


// Structure to represent node of kd tree
struct Node
{
	std::vector<float> point;
	int id;
	Node* left;
	Node* right;

	Node(std::vector<float> arr, int setId)
	:	point(arr), id(setId), left(NULL), right(NULL)
	{}

	~Node()
	{
		delete left;
		delete right;
	}
};

struct KdTree
{
	Node* root;

	KdTree()
	: root(NULL)
	{}

	~KdTree()
	{
		delete root;
	}

	/** helper function inserts node into tree */
	void insertNode(Node** parent, Node* newNode, uint depth) {

        if (*parent == NULL) {
            *parent = newNode;
            return;
        }

        // based on depth compare x or y coordinate
        uint idx = depth % 2;

        // left - right based on y-value
        if (newNode->point.at(idx) >= (*parent)->point.at(idx)) {
            insertNode(&((*parent)->right), newNode, depth + 1);
        }
        else {
            insertNode(&((*parent)->left), newNode, depth + 1);
        }
	}

	/**
	 * Insert a new point into the tree
	 *
	 * @param point
	 * @param id
	 */
	void insert(std::vector<float> point, int id)
	{
		// create a new node
		Node* newNode = new Node(point, id);

		// place the newly created node correctly with in the root
		insertNode(&root, newNode, 0);
	}

    /** helper function searches tree for points in the neighborhood of a target point. */
    void searchTree(Node* parent, std::vector<float> target, float distanceTol, uint depth) {

        if (parent == NULL) { 
            return;
        }

        // test if parent is in box and if yes test if it is in the neighborhood of
        // of the target point. Otherwise, continue traversing the tree

        // based on depth compare x or y coordinate
        uint idx = depth % 2;

        // left - right based on y-value
        if (target.at(idx) >= parent->point.at(idx)) {
            searchTree(parent->right, target, distanceTol, depth + 1);
        }
        else {
            searchTree(parent->left, target, distanceTol, depth + 1);
        }
    }

	// return a list of point ids in the tree that are within distance of target
	std::vector<int> search(std::vector<float> target, float distanceTol)
	{
		std::vector<int> ids;

		// try to


		return ids;
	}
	

};




