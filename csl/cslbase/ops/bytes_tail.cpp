// bytes_tail.cpp

        }

//*****************************************************************************
// End of the main block of opcodes.
//*****************************************************************************
    } // end of switch block
    CATCH(LispException)
// What follows is my current guess for a good diagnostic...
        if (SHOW_FNAME)
        {   err_printf("Inside: ");
            loop_print_error(basic_elt(litvec, 0));
            err_printf("\n");
        }
// Here I need to scan down the current stack-frame looking for either a
// CATCH or an UNWIND-PROTECT marker.
        for (;;)
        {   unwind_stack(entry_stack, true);
            if (stack == entry_stack) RETHROW;
            r1 = *stack--; r2 = *stack--;
// If the tag matches exit_tag then I must reset pc based on offset (r2)
// and continue. NB need to restore A_reg from exit_value.
            w = int_of_fixnum(r2);
            if (car(r1) == SPID_PROTECT)
            {   // This is an UNWIND catcher
                *++stack =exit_tag; *++stack = fixnum_of_int(exit_reason);
                *++stack = Lmv_list(nil, exit_value);
                ppc = w;
                A_reg = exit_value;
                goto next_opcode;
            }
            else if (exit_reason == UNWIND_THROW && r1 == exit_tag)
            {   ppc = w;
                A_reg = exit_value;
                goto next_opcode;
            }
        }
    END_CATCH;

// end of bytes2.cpp
