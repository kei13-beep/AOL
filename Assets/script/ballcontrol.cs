using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ballcontrol : MonoBehaviour
{
     private Rigidbody2D rb2d;
    
    void Start()
    {
        rb2d = GetComponent<Rigidbody2D>();
        Invoke("GoBall", 1);
    }

   private void GoBall()
   {
    float rand = Random.RandomRange (0,2);
    if (rand < 1) rb2d.AddForce(new Vector2(20, -15));
    else rb2d.AddForce(new Vector2(-20, -15));
   }
   
    void ResetBall() //ini kita buat nilai transform jadi 0
    {
        rb2d.velocity = Vector2.zero;
        transform.position = Vector2.zero;
    }

    void RestartGame()
    {
        //Debug.Log("Restart!");
        ResetBall();
        Invoke("GoBall", 1);
    }

    void OnCollisionEnter2D(Collision2D coll)
    {
        if (coll.collider.CompareTag("Player")) //jika terkena player
        {

           // StartCoroutine(FireTriggger());
            Vector2 vel;
            vel.x = rb2d.velocity.x;
            vel.y = (rb2d.velocity.y / 2) + (coll.collider.attachedRigidbody.velocity.y / 3); //mengambil nilai velocity player
            rb2d.velocity = vel;

        }
    }
}
