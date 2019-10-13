================================================================================
    BIBLIOTH�QUE MFC (MICROSOFT FOUNDATION CLASS) : Vue d'ensemble du projet 
    MultiEchiquier
===============================================================================

L'Assistant Application a cr�� cette application MultiEchiquier pour
vous. Cette application ne montre pas seulement l'essentiel de l'utilisation de 
Microsoft Foundation Classes, mais constitue �galement un point de d�part pour 
l'�criture de votre application.

Ce fichier contient un r�sum� du contenu de chacun des fichiers qui constituent
votre application MultiEchiquier.

MultiEchiquier.vcproj
    Il s'agit du fichier projet principal pour les projets VC++ g�n�r�s � 
    l'aide d'un Assistant Application.
    Il contient des informations sur la version de Visual C++ utilis�e pour 
    g�n�rer le fichier ainsi que des informations relatives aux plateformes, 
    configurations et fonctionnalit�s projet que vous avez s�lectionn�es dans 
    l'Assistant Application.

MultiEchiquier.h
    Il s'agit du fichier d'en-t�te principal de l'application. Il inclut 
    d'autres en-t�tes sp�cifiques au projet (dont Resource.h) et d�clare la 
    classe d'application CMultiEchiquierApp.

MultiEchiquier.cpp
    Il s'agit du fichier source principal de l'application qui contient la 
    classe d'application CMultiEchiquierApp.

MultiEchiquier.rc
    Il s'agit de la liste de toutes les ressources Microsoft Windows utilis�es 
    par le programme. Il inclut les ic�nes, les bitmaps et les curseurs qui 
    sont stock�s dans le sous-r�pertoire RES. Ce fichier peut �tre directement 
    modifi� dans Microsoft Visual C++. Vos ressources de projet se trouvent 
    dans 1036.

res\MultiEchiquier.ico
    Il s'agit du fichier ic�ne utilis� comme ic�ne de l'application. Cette 
    ic�ne est incluse par le fichier de ressources principal 
    MultiEchiquier.rc.

res\MultiEchiquier.rc2
    Ce fichier contient les ressources qui ne sont pas modifi�es par 
    Microsoft Visual C++. Vous devez placer toutes les ressources non 
    modifiables par l'�diteur de ressources dans ce fichier.

/////////////////////////////////////////////////////////////////////////////

Pour la fen�tre frame principale :
    Le projet inclut une interface MFC standard.

MainFrm.h, MainFrm.cpp
    Ces fichiers contiennent la classe de frame CMainFrame, qui 
    est d�riv�e de
    CMDIFrameWnd et qui contr�le toutes les fonctionnalit�s du frame MDI.

res\Toolbar.bmp
    Ce fichier bitmap permet de cr�er des images en mosa�que pour la barre 
    d'outils.
    La barre d'outils et la barre d'�tat initiales sont construites dans la 
    classe CMainFrame. Modifiez le bitmap de cette barre 
    d'outils � l'aide de l'�diteur de ressources et mettez � jour le tableau 
    IDR_MAINFRAME TOOLBAR dans MultiEchiquier.rc afin d'ajouter des 
    boutons � la barre d'outils.
/////////////////////////////////////////////////////////////////////////////

Pour la fen�tre frame enfant :

ChildFrm.h, ChildFrm.cpp
    Ces fichiers d�finissent et impl�mentent la classe 
    CChildFrame, qui prend en charge les fen�tres enfants dans 
    une application MDI.

/////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////

Autres fonctionnalit�s :

Contr�les ActiveX
    L'application prend en charge l'utilisation de contr�les ActiveX.

/////////////////////////////////////////////////////////////////////////////

Autres fichiers standard :

StdAfx.h, StdAfx.cpp
    Ces fichiers permettent de g�n�rer un fichier d'en-t�te pr�compil� (PCH) 
    nomm� MultiEchiquier.pch et un fichier de types pr�compil� nomm� 
    StdAfx.obj.

Resource.h
    Il s'agit du ficher d'en-t�te standard, qui d�finit les nouveaux ID de 
    ressources.
    Microsoft Visual C++ lit et met � jour ce fichier.

MultiEchiquier.manifest
	Les fichiers manifestes d'application sont utilis�s par Windows XP pour 
        d�crire la d�pendance d'une application	vis � vis de versions 
        sp�cifiques d'assemblys cote � cote. Le chargeur utilise ces 
        informations pour charger l'assembly appropri� � partir du cache de 
        l'assembly ou l'assembly priv� � partir de l'application. Le manifeste 
        d'application peut �tre inclus afin d'�tre redistribu� en tant que 
        fichier manifeste externe install� dans le m�me dossier que le fichier 
        ex�cutable de l'application ; il peut �galement �tre inclus dans le 
        fichier ex�cutable en tant que ressource.
/////////////////////////////////////////////////////////////////////////////

Autres remarques :

L'Assistant Application utilise "TODO:" pour indiquer les parties du code 
source que vous devez ajouter ou personnaliser.

Si votre application utilise une biblioth�que MFC dans une DLL partag�e, vous 
devez redistribuer les DLL MFC. Si votre application utilise une autre langue 
que celle d�finie dans les param�tres r�gionaux du syst�me d'exploitation, vous 
devez �galement redistribuer les MFC90XXX.DLL des ressources localis�es 
correspondantes.
Pour plus d'informations sur ces deux rubriques, consultez la section relative 
� la redistribution des applications Visual C++ dans la documentation MSDN.

/////////////////////////////////////////////////////////////////////////////
