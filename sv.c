/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:43:49 by magrass           #+#    #+#             */
/*   Updated: 2026/05/12 22:37:50 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>


#define $initArrayList(Type) ({              \
    size_t cap = 4;                          \
    Type* item = malloc(sizeof(Type) * cap); \
    (ArrayList##Type) {                      \
        .items = item,                       \
        .len = 0,                            \
        .cap = cap,                          \
    };                                       \
})

// Dynamic arrray of string views
typedef struct s_sv_da {
    t_sv* items;
    size_t size;
} t_sv_da;

t_sv_da init_sv_da()
{

}

t_sv splitSVByChar(t_sv sv, char splitBy)
{
    t_sv svList = $initArrayList(SV);
    size_t prevSplit = 0;
    for (size_t i = 0; i < sv.size; ++i) {
        if (sv.str[i] == splitBy) {
            t_sv slicedSv = svSlice(sv, prevSplit, i - prevSplit);
            $append((&svList), slicedSv);
            prevSplit = i + 1;
        }
    }
    // Add the last segment after the final delimiter
    if (prevSplit < sv.len) {
        SV slicedSv = svSlice(sv, prevSplit, sv.len - prevSplit);
        $append((&svList), slicedSv);
    }
    return svList;
}