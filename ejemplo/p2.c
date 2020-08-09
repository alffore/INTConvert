/**
 * comnpilar con: gcc p2.c -lproj
 */
#include <stdio.h>
#include <proj.h>

int main (void) {
    PJ_CONTEXT *C;
    PJ *P;
    PJ* P_for_GIS;
    PJ_COORD a, b;

    /* or you may set C=PJ_DEFAULT_CTX if you are sure you will     */
    /* use PJ objects from only one thread                          */
    C = proj_context_create();

    P = proj_create_crs_to_crs (C,
                                "EPSG:6372",
                                "EPSG:4326",
                                NULL);

    if (0==P) {
        fprintf(stderr, "Oops\n");
        return 1;
    }

    /* This will ensure that the order of coordinates for the input CRS */
    /* will be longitude, latitude, whereas EPSG:4326 mandates latitude, */
    /* longitude */
    P_for_GIS = proj_normalize_for_visualization(C, P);
    if( 0 == P_for_GIS )  {
        fprintf(stderr, "Oops\n");
        return 1;
    }
    proj_destroy(P);
    P = P_for_GIS;

   /*2470517.824300,1155028.588300*/
    a = proj_coord (2470517.824300, 1155028.588300, 0, 0);

    /* transform to UTM zone 32, then back to geographical */
    b = proj_trans (P, PJ_FWD, a);
    printf ("longitud: %.6f, latitud: %.6f\n", b.lp.lam, b.lp.phi);
    b = proj_trans (P, PJ_INV, b);
    printf ("Este: %.6f, Norte: %.6f\n", b.enu.e, b.enu.n);

    /* Clean up */
    proj_destroy (P);
    proj_context_destroy (C); /* may be omitted in the single threaded case */
    return 0;
}
