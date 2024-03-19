using System.Linq;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Runtime.CompilerServices;

namespace MySystem
{

    class Program
    {

        static void Main(string[] args)
        {
            Node node = new Node(0);
            Node node2 = new Node(1);
            Node node3 = new Node(2);
            Node node4 = new Node(3);
            Node node5 = new Node(4);
            Node node6 = new Node(5);
            Node node7 = new Node(6);
            node.child_node.Add(node2);
            node.child_node.Add(node3);
            node.child_node.Add(node4);
            node.child_node.Add(node5);
            node.child_node.Add(node6);
            node.child_node.Add(node7);
            Stack<Node> stack = new Stack<Node>();

            while (node.child_node.Count == 0)
            {
                stack.Push(node);
                for (int i = 0; i < node.child_node.Count; i++)
                {
                    Console.WriteLine(node.child_node[i].NodeNumber);
                    stack.Push(node.child_node[i]);
                }
                stack.Pop();
            }

            node2.child_node.Add(node);
        }
    }


    class Node
    {
        public Node(int number) { NodeNumber = number; }
        public int NodeNumber;

        public List<Node> child_node = new List<Node>();
    }
}

