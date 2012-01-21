
#ifndef BASE_EXPORT_HPP
#define BASE_EXPORT_HPP

#ifdef _WIN32
#  ifdef base_EXPORTS
#    define BASE_EXPORT		__declspec( dllexport )
#  else
#    define BASE_EXPORT		__declspec( dllimport )
#  endif
#else
#  define BASE_EXPORT
#endif

#endif

