#include <iostream>

int main()
{
    // Initialize the input variables
    int small_boxes{};
    int med_boxes{};
    int large_boxes{};
    int total_parts{};

    while (true)
    {
        // Query for box count and assign to variables
        std::cout << "How many boxes are available (Small/Medium/Large) " << '\n';
        std::cin >> small_boxes >> med_boxes >> large_boxes;

        // Ensure the negative values are not input
        if (small_boxes < 0 || med_boxes < 0 || large_boxes < 0)
        {
            std::cout << "Negative values are not permited, please try again " << '\n';
        }
        else
        {
            break;
        }
    }
    // Query for Part numbers
    while (true)
    {
        // Query and assign number of parts
        std::cout << "How many total parts are exist? ";
        std::cin >> total_parts;

        // Ensure that negative values are not input
        if (total_parts < 0)
        {
            std::cout << "Negative values are not permited, please try again " << '\n';
        }
        else
        {
            break;
        }
    }
    std::cout << "**************" << '\n';
    // The following code tests all 6 fit combinations of Large, Medium, and Small
    // Ultimately saving the combination that has the least leftover parts

    // Initialize Final output variables

    int final_large{};
    int final_med{};
    int final_small{};
    int final_remaining_parts{};

    // Assign the case variables
    int remaining_parts{total_parts};
    int remaining_large{large_boxes};
    int remaining_med{med_boxes};
    int remaining_small{small_boxes};

    // CASE 1: Large, Medium, then Small

    // Case 1: Large

    //Note: All large, medium, and small instances for each case follow exactly this progrssion so I will only be commenting this one

    // if Large boxes exist
    if (large_boxes != 0)
    {
        //Continue running while there are still boxes and parts to use
        while (remaining_parts <= total_parts && remaining_large <= large_boxes)
        {
            // iterate through each box and number of parts
            remaining_parts = remaining_parts - 25;
            remaining_large = remaining_large - 1;
            // if in the iteration, a negative number appears, add back the previous number of parts and exit the loop
            if (remaining_large < 0 || remaining_parts < 0)
            {
                remaining_parts = remaining_parts + 25;
                remaining_large = remaining_large + 1;
                break;
            }
        }
    }

    // Case 1: Medium
    if (med_boxes != 0)
    {
        while (remaining_parts <= total_parts && remaining_med <= med_boxes)
        {
            remaining_parts = remaining_parts - 12;
            remaining_med = remaining_med - 1;
            if (remaining_med < 0 || remaining_parts < 0)
            {
                remaining_parts = remaining_parts + 12;
                remaining_med = remaining_med + 1;
                break;
            }
        }
    }

    // Case 1: Small
    if (small_boxes != 0)
    {
        while (remaining_parts <= total_parts && remaining_small <= small_boxes)
        {
            remaining_parts = remaining_parts - 7;
            remaining_small = remaining_small - 1;
            if (remaining_small < 0 || remaining_parts < 0)
            {
                remaining_parts = remaining_parts + 7;
                remaining_small = remaining_small + 1;
                break;
            }
        }
    }

    // Assign the final print variables
    final_large = large_boxes - remaining_large;
    final_med = med_boxes - remaining_med;
    final_small = small_boxes - remaining_small;
    final_remaining_parts = remaining_parts;

    // ***************************************************************************

    // CASE 2: Large, Small, then Medium

    // Reset the case variables
    remaining_parts = total_parts;
    remaining_large = large_boxes;
    remaining_med = med_boxes;
    remaining_small = small_boxes;

    // Case 2: Large
    if (large_boxes != 0)
    {
        while (remaining_parts <= total_parts && remaining_large <= large_boxes)
        {
            remaining_parts = remaining_parts - 25;
            remaining_large = remaining_large - 1;
            if (remaining_large < 0 || remaining_parts < 0)
            {
                remaining_parts = remaining_parts + 25;
                remaining_large = remaining_large + 1;
                break;
            }
        }
    }

    // Case 2: Small
    if (small_boxes != 0)
    {
        while (remaining_parts <= total_parts && remaining_small <= small_boxes)
        {
            remaining_parts = remaining_parts - 7;
            remaining_small = remaining_small - 1;
            if (remaining_small < 0 || remaining_parts < 0)
            {
                remaining_parts = remaining_parts + 7;
                remaining_small = remaining_small + 1;
                break;
            }
        }
    }

    // Case 2: Medium
    if (med_boxes != 0)
    {
        while (remaining_parts <= total_parts && remaining_med <= med_boxes)
        {
            remaining_parts = remaining_parts - 12;
            remaining_med = remaining_med - 1;
            if (remaining_med < 0 || remaining_parts < 0)
            {
                remaining_parts = remaining_parts + 12;
                remaining_med = remaining_med + 1;
                break;
            }
        }
    }

    // Check and reassign if more optimal
    if (remaining_parts < final_remaining_parts)
    {

        final_large = large_boxes - remaining_large;
        final_med = med_boxes - remaining_med;
        final_small = small_boxes - remaining_small;
        final_remaining_parts = remaining_parts;
    }

    // ***************************************************************************

    // CASE 3: Medium, Large, then Small

    // Reset the case variables
    remaining_parts = total_parts;
    remaining_large = large_boxes;
    remaining_med = med_boxes;
    remaining_small = small_boxes;

    // Case 3: Medium
    if (med_boxes != 0)
    {
        while (remaining_parts <= total_parts && remaining_med <= med_boxes)
        {
            remaining_parts = remaining_parts - 12;
            remaining_med = remaining_med - 1;
            if (remaining_med < 0 || remaining_parts < 0)
            {
                remaining_parts = remaining_parts + 12;
                remaining_med = remaining_med + 1;
                break;
            }
        }
    }

    // Case 3: Large
    if (large_boxes != 0)
    {
        while (remaining_parts <= total_parts && remaining_large <= large_boxes)
        {
            remaining_parts = remaining_parts - 25;
            remaining_large = remaining_large - 1;
            if (remaining_large < 0 || remaining_parts < 0)
            {
                remaining_parts = remaining_parts + 25;
                remaining_large = remaining_large + 1;
                break;
            }
        }
    }

    // Case 3: Small
    if (small_boxes != 0)
    {
        while (remaining_parts <= total_parts && remaining_small <= small_boxes)
        {
            remaining_parts = remaining_parts - 7;
            remaining_small = remaining_small - 1;
            if (remaining_small < 0 || remaining_parts < 0)
            {
                remaining_parts = remaining_parts + 7;
                remaining_small = remaining_small + 1;
                break;
            }
        }
    }
    // Check and reassign if more optimal
    if (remaining_parts < final_remaining_parts)
    {

        final_large = large_boxes - remaining_large;
        final_med = med_boxes - remaining_med;
        final_small = small_boxes - remaining_small;
        final_remaining_parts = remaining_parts;
    }

    // ***************************************************************************

    // CASE 4: Medium, Small, then Large

    // Reset the case variables
    remaining_parts = total_parts;
    remaining_large = large_boxes;
    remaining_med = med_boxes;
    remaining_small = small_boxes;

    // Case 4: Medium
    if (med_boxes != 0)
    {
        while (remaining_parts <= total_parts && remaining_med <= med_boxes)
        {
            remaining_parts = remaining_parts - 12;
            remaining_med = remaining_med - 1;
            if (remaining_med < 0 || remaining_parts < 0)
            {
                remaining_parts = remaining_parts + 12;
                remaining_med = remaining_med + 1;
                break;
            }
        }
    }

    // Case 4: Small
    if (small_boxes != 0)
    {
        while (remaining_parts <= total_parts && remaining_small <= small_boxes)
        {
            remaining_parts = remaining_parts - 7;
            remaining_small = remaining_small - 1;
            if (remaining_small < 0 || remaining_parts < 0)
            {
                remaining_parts = remaining_parts + 7;
                remaining_small = remaining_small + 1;
                break;
            }
        }
    }

    // Case 4: Large
    if (large_boxes != 0)
    {
        while (remaining_parts <= total_parts && remaining_large <= large_boxes)
        {
            remaining_parts = remaining_parts - 25;
            remaining_large = remaining_large - 1;
            if (remaining_large < 0 || remaining_parts < 0)
            {
                remaining_parts = remaining_parts + 25;
                remaining_large = remaining_large + 1;
                break;
            }
        }
    }
    // Check and reassign if more optimal
    if (remaining_parts < final_remaining_parts)
    {

        final_large = large_boxes - remaining_large;
        final_med = med_boxes - remaining_med;
        final_small = small_boxes - remaining_small;
        final_remaining_parts = remaining_parts;
    }

    // ***************************************************************************

    // CASE 5: Small, Large, then Medium

    // Reset the case variables
    remaining_parts = total_parts;
    remaining_large = large_boxes;
    remaining_med = med_boxes;
    remaining_small = small_boxes;

    // Case 5: Small
    if (small_boxes != 0)
    {
        while (remaining_parts <= total_parts && remaining_small <= small_boxes)
        {
            remaining_parts = remaining_parts - 7;
            remaining_small = remaining_small - 1;
            if (remaining_small < 0 || remaining_parts < 0)
            {
                remaining_parts = remaining_parts + 7;
                remaining_small = remaining_small + 1;
                break;
            }
        }
    }

    // Case 5: Large
    if (large_boxes != 0)
    {
        while (remaining_parts <= total_parts && remaining_large <= large_boxes)
        {
            remaining_parts = remaining_parts - 25;
            remaining_large = remaining_large - 1;
            if (remaining_large < 0 || remaining_parts < 0)
            {
                remaining_parts = remaining_parts + 25;
                remaining_large = remaining_large + 1;
                break;
            }
        }
    }

    // Case 5: Medium
    if (med_boxes != 0)
    {
        while (remaining_parts <= total_parts && remaining_med <= med_boxes)
        {
            remaining_parts = remaining_parts - 12;
            remaining_med = remaining_med - 1;
            if (remaining_med < 0 || remaining_parts < 0)
            {
                remaining_parts = remaining_parts + 12;
                remaining_med = remaining_med + 1;
                break;
            }
        }
    }

    // Check and reassign if more optimal
    if (remaining_parts < final_remaining_parts)
    {

        final_large = large_boxes - remaining_large;
        final_med = med_boxes - remaining_med;
        final_small = small_boxes - remaining_small;
        final_remaining_parts = remaining_parts;
    }

    // ***************************************************************************

    // CASE 6: Small, Medium, then Large

    // Reset the case variables
    remaining_parts = total_parts;
    remaining_large = large_boxes;
    remaining_med = med_boxes;
    remaining_small = small_boxes;

    // Case 6: Small
    if (small_boxes != 0)
    {
        while (remaining_parts <= total_parts && remaining_small <= small_boxes)
        {
            remaining_parts = remaining_parts - 7;
            remaining_small = remaining_small - 1;
            if (remaining_small < 0 || remaining_parts < 0)
            {
                remaining_parts = remaining_parts + 7;
                remaining_small = remaining_small + 1;
                break;
            }
        }
    }

    // Case 6: Medium
    if (med_boxes != 0)
    {
        while (remaining_parts <= total_parts && remaining_med <= med_boxes)
        {
            remaining_parts = remaining_parts - 12;
            remaining_med = remaining_med - 1;
            if (remaining_med < 0 || remaining_parts < 0)
            {
                remaining_parts = remaining_parts + 12;
                remaining_med = remaining_med + 1;
                break;
            }
        }
    }

    // Case 6: Large
    if (large_boxes != 0)
    {
        while (remaining_parts <= total_parts && remaining_large <= large_boxes)
        {
            remaining_parts = remaining_parts - 25;
            remaining_large = remaining_large - 1;
            if (remaining_large < 0 || remaining_parts < 0)
            {
                remaining_parts = remaining_parts + 25;
                remaining_large = remaining_large + 1;
                break;
            }
        }
    }

    // Check and reassign if more optimal
    if (remaining_parts < final_remaining_parts)
    {

        final_large = large_boxes - remaining_large;
        final_med = med_boxes - remaining_med;
        final_small = small_boxes - remaining_small;
        final_remaining_parts = remaining_parts;
    }

    // ***************************************************************************

    // Print Output
    std::cout << "Large boxes used: " << final_large << '\n';
    std::cout << "Medium boxes used: " << final_med << '\n';
    std::cout << "Small boxes used: " << final_small << '\n';
    std::cout << "**************" << '\n';
    std::cout << "Total parts remaining: " << final_remaining_parts << '\n';
    
}