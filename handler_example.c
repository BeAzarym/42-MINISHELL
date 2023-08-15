

#include "minishell/includes/minishell.h"

void	handle_sigtstp(int sig);
void	handle_sigcont(int sig);

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					x;

	sa.sa_handler = &handle_sigcont;
	sa.sa_flags = SA_RESTART; // because of combination of SIGTSTP and scanf
	sigaction(SIGTSTP, &sa, NULL);  // 3d param : stores the old sigaction
	// signal(SIGTSTP, &handle_sigtstp); => avoid its use (portability issues)
	printf("Input number: \n");
    scanf("%d", &x);
    printf("Result %d * 5 = %d\n", x, x * 5);

    return (0);

}

void	handle_sigtstp(int sig)
{
	printf("Stop not allowed\n");
}

void	handle_sigcont(int sig)
{
	printf("Input number: ");
	fflush(stdout);	// for it not to wait anything instead of printing
}