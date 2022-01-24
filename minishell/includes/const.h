/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:31:39 by elim              #+#    #+#             */
/*   Updated: 2022/01/23 22:24:24 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

# define STDIN_BACKUP 100
# define STDOUT_BACKUP 101

# define D_QUOTE 34
# define S_QUOTE 39
# define PIPE 124

# define REDIR_X 0
# define REDIR_L 1
# define REDIR_R 2
# define REDIR_LL 3
# define REDIR_RR 4
# define REDIR_FILE 5
# define REDIR_SYNTAX_ERR 6

# define ERROR 1
# define ERR_CMD_NOT_FOUND 1
# define ERR_NO_SUCH_FILE 2
# define ERR_TOO_MANY_ARGS 3
# define ERR_REDIR_SNTAX 4
# define ERR_NUM_ARG_REQUIRED 5
# define ERR_EXPORT 6
# define ERR_UNSET 7
# define ERR_NO_ENV_HOME 8

# define STR_CMD_NOT_FOUND ": command not found\n"
# define STR_NO_SUCH_FILE ": No such file or directory\n"
# define STR_TOO_MANY_ARGS ": Too may argments\n"
# define STR_NUM_ARG_REQUIRED ": numeric argument required\n"
# define STR_REDIR_SYNTAX "syntax error near unexpected token `"
# define STR_EXPORT "': not a valid identifier\n"
# define STR_UNSET "': not a valid identifier\n"

# define STR_NL "newline"
# define STR_L "<"
# define STR_R ">"
# define STR_LL "<<"
# define STR_RR ">>"

#endif
